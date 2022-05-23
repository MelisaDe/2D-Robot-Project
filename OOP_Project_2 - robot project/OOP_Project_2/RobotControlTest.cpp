/**
 * @file RobotControlTest.cpp
 * @Author Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Controlling the robot's moves.
 */
#include "PioneerRobotAPI.h"
#include "RobotControl.h"
#include"Pose.h"
#include <iostream>
using namespace std;
LaserSensor sens1;
SonarSensor sens;
RobotInterface* piooner = new PioneerRobotInterface;
Pose p;
RobotControl robot(piooner, &sens, &sens1, &p);
/*!< robot is created RobotControl* type object to represent robot. */
//print the position datas of robot.
void print();

///The main for create robot object type of RobotControl and call functions from class.
int main() {
	float sonars[16];
	float laserData[500];
	int temp = 0;
	int accessCode;
	cout << "Enter the access code: ";
	cin >> accessCode;

	if (robot.openAccess(accessCode)) {
		cout << "Access is true." << endl;
		robot.access_control = true;
	}
	else { cout << "Access is false." << endl; robot.access_control = false; }

	if (!robot.connectRobot()) {
		temp = 1;
		cout << "Could not connect..." << endl;
		return 0;
	}

	cout << endl;
	robot.forward_(100);
	cout << "Robot is moving with 100m/s speed..." << endl;
	Sleep(1000);
	print();


	robot.turnLeft();
	cout << "Robot is turning left..." << endl;
	Sleep(1000);
	print();


	robot.stopTurn();
	cout << "Robot is stop turning..." << endl;
	Sleep(1000);
	print();


	robot.turnRight();
	cout << "Robot is turning right..." << endl;
	Sleep(1000);
	print();


	robot.backward(100);
	cout << "Robot is moving back with 100m/s speed..." << endl;
	Sleep(1000);
	print();

	robot.forward_(150);
	cout << "Robot is moving with 150m/s speed..." << endl;
	Sleep(1000);
	print();

	robot.turnLeft();
	cout << "Robot is turning left..." << endl;
	Sleep(1000);
	print();

	robot.stopTurn();
	cout << "Robot is stop turning..." << endl;
	Sleep(1000);
	print();

	robot.forward_(1000);
	cout << "Robot is moving with 1000m/s speed..." << endl;
	Sleep(1000);
	print();


	robot.stopTurn();
	cout << "Robot is stop turning..." << endl;
	Sleep(1000);
	print();


	cout << "Are poses written to file? " << robot.recordPath() << endl;
	cout << "Is path cleared? " << robot.clearPath() << endl;


	robot.stopMove();
	robot.disconnectRobot();
	cout << "Press any key to exit...";
	getchar();
	
	free(piooner);

	return 0;
}
void print() {
	robot.updatePose();
	cout << "Is current pose added to path? " << robot.addToPath() << endl;
	cout << "MyPose is (" << p.getX() << "," << p.getY() << "," << p.getTh() << ")" << endl;
}
