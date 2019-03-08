package frc.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import frc.robot.RobotMap;
import frc.robot.commands.SensorCommand;

public class Sensors extends Subsystem {

  public static final int BUFFER_SIZE = 2;
  public static String lastRead = null;
  public static boolean readReady = false;

  @Override
  public void initDefaultCommand() {
    // Set the default command for a subsystem here.
    // setDefaultCommand(new MySpecialCommand());
    setDefaultCommand(new SensorCommand());
  }

  public void sensors(){

    try{
      if (RobotMap.serial.getBytesReceived() <= 0)
      {
          return;
      }
      
        // if(!readReady){
        //   String str = RobotMap.serial.readString();
        // }
        
        String str = RobotMap.serial.readString();
        System.out.println(str);
        
        // String[] tokens = str.split("/n");
  
        // while (str.indexOf('\n', 0) == -1)
        // {
        //   str += RobotMap.serial.readString(1);
        // }
  
        if (lastRead != null)
        {
        str = lastRead + str;
        lastRead = null;
        }
  
        int nextLN = str.indexOf('\n', 0);
        if (nextLN < 0)
        {
        lastRead = str;
          return;
        }
  
        // System.out.println("Index = " + nextLN + " strlen = " + str.length());
  
        if (nextLN < str.length() - 1)
        {
          lastRead = str.substring(nextLN);
        }
      
        System.out.println();
        System.out.print(str);
  
        MyPair result = parseInput(str);
  
        if (result == null)
        {
          return;
        }
      
        // result.value
        // System.out.println("Result id = " + result.id + " value = " + result.value);
  
        if(result.id == 'a'){
          RobotMap.tof1 = result.value;
          SmartDashboard.putNumber("Tof1", RobotMap.tof1);
          // System.out.print(RobotMap.tof1);
          // System.out.print("this is result " + result.value);
        }else if(result.id == 'b'){
          RobotMap.tof2 = result.value;
          SmartDashboard.putNumber("Tof2", RobotMap.tof2);
        }else if(result.id == 'c'){
          RobotMap.IR1 = result.value;
          SmartDashboard.putNumber("IR1", RobotMap.IR1);
        }else if(result.id == 'd'){
          RobotMap.IR2 = result.value;
          SmartDashboard.putNumber("IR2", RobotMap.IR2);
        }else if(result.id == 'e'){
          RobotMap.IR3 = result.value;
          SmartDashboard.putNumber("IR3", RobotMap.IR3);
        }
  
        System.out.flush();

    }catch(Exception e){

      SmartDashboard.putString("Error", "It errored");

    }
  }

  public class MyPair {
    public char id;
    public int  value;
  }

  public MyPair parseInput(String input)
  {
    MyPair pair = new MyPair();

    pair.id = input.charAt(0);

    if (pair.id > 'z' || pair.id < 'a')
    {
      return null;
    }

    pair.value = Integer.parseInt(input.substring(1, input.length() - 2));

    return pair;
  }
}