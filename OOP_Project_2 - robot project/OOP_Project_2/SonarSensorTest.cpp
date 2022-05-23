/**
 * @file SonarSensorTest.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com)
 * @date January, 2021
 * @brief  Test source file of class that stores the sonar sensor's datas.
 */
#include <iostream>
#include "PioneerRobotAPI.h"
#include "SonarSensor.h"
#include"PioneerRobotInterface.h"
#include"RobotControl.h"
#include"Pose.h"

using namespace std;
RangeSensor* sens = new SonarSensor;
RangeSensor* sens1 = new LaserSensor;
RobotInterface* piooner = new PioneerRobotInterface;
Pose p;
RobotControl robot(piooner, sens, sens1, &p);
/*!< robot is created SonarSensor type object */

float sonars[16];/*!< sonars is created float type array  to store sonar sensor datas.*/
//function for print the sonarsensor datas.
void print();
///Main function to create SonarSensor object and call functions from class.
int main() {

	if (!robot.connectRobot()) {
		cout << "Could not connect..." << endl;
		return 0;
	}
	cout << endl << endl << "WHEN ROBOT IS MOVING SONAR SENSORS ARE CHANGING..." << endl << endl;
	robot.forward_(100);
	Sleep(1000);
	print();
	robot.turnLeft();
	Sleep(1000);
	print();
	robot.turnRight();
	Sleep(1000);
	print();

	robot.turnRight();
	Sleep(1000);
	print();
	robot.forward_(150);
	Sleep(1000);
	print();

	cout << "Range of index 2:  " << robot.sensorS->getRange(2) << endl;
	cout << "Range of index 7:  " << sonars[7] << endl;
	int index;
	cout << "Index of max range: " << robot.sensorS->getMax(index) << endl;
	cout << "Index of min range: " << robot.sensorS->getMin(index) << endl;
	cout << "Angle of index 5: " << robot.sensorS->getAngle(5) << endl << endl;

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
	cout << endl << endl << "WHEN ROBOT IS MOVING SONAR SENSOR IS CHANGING..." << endl << endl;
	cout << "Range of index 2:  " << robot.sensorS->getRange(2) << endl;
	cout << "Range of index 7:  " << sonars[7] << endl;
	cout << "Index of max range: " << robot.sensorS->getMax(index) << endl;
	cout << "Index of min range: " << robot.sensorS->getMin(index) << endl;
	cout << "Angle of index 5: " << robot.sensorS->getAngle(5) << endl << endl;

	robot.stopMove();
	cout << "LAST SONAR SENSOR" << endl << endl;
	print();

	cout << "Press any key to exit...";
	getchar();

	robot.disconnectRobot();
	delete sens, sens1, piooner;
	return 0;

}
void print() {
	cout << "Sonar ranges are [ ";
	robot.robotinterface->updateSensors();
	for (int i = 0; i < 16; i++) {
		sonars[i] = robot.sensorS->getRange(i);
		cout << robot.sensorS->getRange(i) << " ";
	}
	cout << "]" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
}