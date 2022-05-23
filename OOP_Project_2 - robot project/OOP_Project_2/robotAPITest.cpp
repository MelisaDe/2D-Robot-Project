#include "PioneerRobotAPI.h"
#include <iostream>
using namespace std;

PioneerRobotAPI *robot;
float sonars[16];
float laserData[181];

void print() {
	cout << "MyPose is (" << robot->getX() << "," << robot->getY() << "," << robot->getTh() << ")" << endl;
	cout << "Sonar ranges are [ ";
	robot->getSonarRange(sonars);
	for (int i = 0; i < 16; i++) {
		cout << sonars[i] << " ";
	}
	cout << "]" << endl;
	cout << "Laser ranges are [ ";
	robot->getLaserRange(laserData);
	for (int i = 0; i < 181; i++) {
		cout << laserData[i] << " ";
	}
	cout << "]" << endl;
}

int main() {

	robot=new PioneerRobotAPI;

	if (!robot->connect()) {
		cout << "Could not connect..." << endl;
		return 0;
	}

	robot->moveRobot(100);
	print();

	robot->turnRobot(PioneerRobotAPI::DIRECTION::left);
	Sleep(1000);
	print();

	robot->turnRobot(PioneerRobotAPI::DIRECTION::forward);
	Sleep(1000);
	print();

	robot->turnRobot(PioneerRobotAPI::DIRECTION::right);
	Sleep(1000);
	print();

	robot->stopRobot();
	robot->setPose(100, 200, 30);
	Sleep(1000);
	print();

	cout << "Press any key to exit...";
	getchar();

	robot->disconnect();
	delete robot;
	return 0;

}