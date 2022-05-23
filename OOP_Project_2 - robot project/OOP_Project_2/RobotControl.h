/**
 * @file RobotControl.h
 * @Author Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Header file of class that controlling the robot's moves.
 */
#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H
#include <iostream>
#include"RangeSensor.h"
#include"RobotInterface.h"
#include "PioneerRobotAPI.h"
#include "SonarSensor.h"
#include "LaserSensor.h"
#include "Pose.h"
#include "Path.h"
#include"PioneerRobotInterface.h"
#include"RobotOperator.h"

using namespace std;
//! A class to controlling robot.
/*!
 This class controlling the robot's moves and stores Pose datas.
*/
class RobotControl {
private:

    Pose* position;
    Path* p;
    RobotOperator* admin;

public:
    bool access_control = false;
    RangeSensor* sensorS;
    RangeSensor* sensorL;

    RobotInterface* robotinterface;
    RobotControl(RobotInterface* robot, RangeSensor* sens, RangeSensor* sens1, Pose* pose);
    ~RobotControl();
    /** \brief function for turning robot to left.
     */
    bool connectRobot();
    void disconnectRobot();
    void turnLeft();
    /** \brief function for turning robot to right.
     */
    void turnRight();
    /** \brief function for moving robot forward.
      * \param speed_ is float argument to represent speed of robot.
     */
    void forward_(float speed);
    /** \brief function for print position's datas.
     */
    void print();
    /** \brief function for moving robot backward.
      * \param speed_ is float argument to represent speed of robot.
      */
    void backward(float speed);
    /** \brief function for get position.
     * \return position
     */
    Pose getPose();
    /** \brief function for setting position from given position.
       * \param Pose is pose argument to represent position.
      */
    virtual void setPose(Pose*);
    /** \brief function for stop robot's turning.
     */
    void stopTurn();
    /** \brief function for stop robot's move.
     */
    void stopMove();
    void updatePose();

    bool addToPath();
    bool clearPath();
    bool recordPath();
    bool closeAccess(int accessCode);
    bool openAccess(int accessCode);

};
#endif

