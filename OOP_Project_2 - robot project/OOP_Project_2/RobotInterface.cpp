#include"RobotInterface.h"
#include"Pose.h"
#include"RangeSensor.h"
#include"LaserSensor.h"
#include"SonarSensor.h"


void RobotInterface::setPose(Pose* pose) {
	position = pose;
}
Pose RobotInterface::getPose() {
	return *position;
}
