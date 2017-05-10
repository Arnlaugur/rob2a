#pragma config(Sensor, in1,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, dgtl1,  SonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           ArmMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           ClawMotor,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                             	    - Triple Sensor Line Tracking -                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses 3 VEX Line Follower Sensors to track a black line on a light(er) surface.       *|
|*  There is a two second pause at the beginning of the program.                                      *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Lighting conditions, line darkness, and surface lightness change from place to place,       *|
|*        so the value of 'threshold' may need to be changed to better suit your environment.         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor  - Port 2     rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor  - Port 3     leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Analog - Port 1     lineFollowerRIGHT   VEX Light Sensor      Front-right, facing down          *|
|*    Analog - Port 2     lineFollowerCENTER  VEX Light Sensor      Front-center, facing down         *|
|*    Analog - Port 3     lineFollowerLEFT    VEX Light Sensor      Front-left, facing down           *|
\*-----------------------------------------------------------------------------------------------4246-*/

void followLine(){
   int threshold = 2800;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */
  while(SensorValue(SonarSensor) >= 21 || SensorValue(SonarSensor) == -1)
  {

    // RIGHT sensor sees dark:
    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 100;
      motor[rightMotor] = -60;
    }
    motor[leftMotor]  = 0;
      motor[rightMotor] = 0;
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 100;
      motor[rightMotor] = 100;
    }
    motor[leftMotor]  = 0;
      motor[rightMotor] = 0;
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = -60;
      motor[rightMotor] = 100;
    }
    motor[leftMotor]  = 0;
      motor[rightMotor] = 0;
     if(SensorValue(lineFollowerCENTER) < threshold && SensorValue(lineFollowerLEFT) < threshold && SensorValue(lineFollowerRIGHT) < threshold)
     {
       motor[leftMotor] = 70;
       motor[rightMotor] = -70;
     }
  }
}
void closeClaw(){
  motor[ClawMotor] = 70;
  wait1Msec(2000);
  motor[ClawMotor] = 0;
}
void openClaw(){
  motor[ClawMotor] = -70;
  wait1Msec(200);
  motor[ClawMotor] = 0;
}
void armDown(){
  motor[ArmMotor] = -70;
  wait1Msec(500);
  motor[ArmMotor] = 0;
}
void armUp(){
  motor[ArmMotor] = -70;
  wait1Msec(500);
  motor[ArmMotor] = 0;
}
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task main()
{

	while(true)
	{
	if(vexRT[Btn7L] == 1){
	while(1 == 1)
	{
	openClaw();
  wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.
  followLine();
  closeClaw();
  armUp();
  followLine();
  openClaw();
                            /* surfaces, adding them together, then dividing by 2. */
  StopAllTasks();
}
}
}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
