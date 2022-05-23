/**
 * @file LaserSensorTest.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com)
 * @date January, 2021
 * @brief  Test source file of class that stores the laser ranges's datas.
 */
#include <iostream>
#include "PioneerRobotAPI.h"
#include "LaserSensor.h"
#include"PioneerRobotInterface.h"
#include"RobotControl.h"
#include"Pose.h"
using namespace std;
RangeSensor* sens = new SonarSensor;
RangeSensor* sens1 = new LaserSensor;
RobotInterface* piooner = new PioneerRobotInterface;
Pose p;
RobotControl robot(piooner, sens, sens1, &p);
float laserData[181];/*!< laserDatas is created float type array to store laser sensor datas.*/
//function for print the lasersensor datas.
void print();
///Main function to create LaserSensor object and call functions from class.
int main() {

	
	if (!robot.connectRobot()) {
		cout << "Could not connect..." << endl;
		return 0;
	}

	cout << endl << endl << "WHEN ROBOT IS MOVING LASER RANGES ARE CHANGING..." << endl << endl;
	robot.forward_(100);
	Sleep(1000);
	print();

	robot.turnLeft();
	Sleep(1000);
	print();

	robot.stopTurn();
	Sleep(1000);
	print();

	robot.turnRight();
	Sleep(1000);
	print();

	robot.forward_(150);
	Sleep(1000);
	print();

	robot.turnLeft();
	Sleep(1000);
	print();

	robot.stopTurn();
	Sleep(1000);
	print();

	robot.backward(200);
	Sleep(1000);
	print();

	robot.forward_(250);
	Sleep(1000);
	print();

	cout <<endl<<"Range of index 20:  " << robot.sensorL->getRange(20) << endl;
	cout << "Range of index 71:  " << laserData[71] << endl;
	int index;
	cout << "Index of max range: " << robot.sensorL->getMax(index) << endl;
	cout << "Index of min range: " << robot.sensorL->getMin(index) << endl;
	cout << "Angle of index 88: " << robot.sensorL->getAngle(88) << endl;
	float angle;
	cout << "Closest range between 20 and 160: " << robot.sensorL->getClosestRange(20, 160, angle) << endl;
	cout << "Closest range's angle: " << angle << endl;

	robot.stopMove();
	print();

	cout << "Press any key to exit...";
	getchar();

	robot.disconnectRobot();
	delete sens, sens1, piooner;
	return 0;

}
void print() {
	cout << endl;
	cout << "Laser ranges are [ ";
	robot.robotinterface->updateSensors();
	for (int i = 0; i < 181; i++) {
		laserData[i] = robot.sensorL->getRange(i);
		cout << robot.sensorL->getRange(i) << " ";
	}
	cout << "]" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "---------------------------------------------------------------------------------"<< endl;
	cout << endl;
}
