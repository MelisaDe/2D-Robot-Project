/**
 * @file RobotControl.h
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Header file of class that controlling the robot's moves.
 */

#include <iostream>
#include"RobotInterface.h"
#include"PioneerRobotInterface.h"
#include"PioneerRobotAPI.h"

bool PioneerRobotInterface::connectRobot() {
    return connect();
}
void PioneerRobotInterface::disconnectRobot() {
    disconnect();
}

void PioneerRobotInterface::turnLeft() {
    turnRobot(left);
}

void PioneerRobotInterface::turnRight() {
    turnRobot(right);
}

void PioneerRobotInterface::forward_(float speed) {
    state = 1;
    moveRobot(speed);
}

void PioneerRobotInterface::print() {
    float temp;
    temp = getX();
    cout << "x: " << temp;
    temp = getY();
    cout << "y: " << temp;
    temp = getTh();
    cout << "Angle: " << temp;
}
void PioneerRobotInterface::backward(float speed) {
    state = 1;
    speed *= -1;
    moveRobot(speed);
}
Pose PioneerRobotInterface::getPose() {
    Pose p;
    p.setX(getX());
    p.setY(getY());
    p.setTh(getTh());
    return p;
}

void PioneerRobotInterface::setPose(Pose* pose) {
    PioneerRobotAPI::setPose(pose->getX(), pose->getY(), pose->getTh());
}

void PioneerRobotInterface::stopTurn() {
    turnRobot(forward);
}

void PioneerRobotInterface::stopMove() {
    state = 0;
    stopRobot();
}
void PioneerRobotInterface::updateSensors() {
    float a[1000];
    float b[1000];
    getSonarRange(a);
    rangeSensorS->updateSensor(a);
    getLaserRange(b);
    rangeSensorL->updateSensor(b);
}
void PioneerRobotInterface::updaterobot() {
    float myx, myy, myth;
    myx = getX();
    myy = getY();
    myth = getTh();
    position->setX(myx);
    position->setY(myy);
    position->setTh(myth);
}
void PioneerRobotInterface::setSensors(RangeSensor* s, RangeSensor* a) {
    rangeSensorS = s;
    rangeSensorL = a;
}

