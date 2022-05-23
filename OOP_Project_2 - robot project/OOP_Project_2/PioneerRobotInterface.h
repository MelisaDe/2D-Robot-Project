/**
 * @file RobotControl.h
 * @Author Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Header file of class that controlling the robot's moves.
 */

#ifndef PIONEERROBOTINTERFACE_H
#define PIONEERROBOTINTERFACE_H
#include <iostream>
#include"PioneerRobotAPI.h"
#include"RobotInterface.h"
#include"Node.h"
#include"Pose.h"

 //! A class to controlling robot.
 /*!
  This class controlling the robot's moves and stores Pose datas.
 */

class PioneerRobotInterface :public RobotInterface, public PioneerRobotAPI {
private:

public:
    
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
    void setPose(Pose*);
    /** \brief function for stop robot's turning.
     */
    void stopTurn();
    /** \brief function for stop robot's move.
     */
    void stopMove();
    void updateSensors();
    void updaterobot();
    void setSensors(RangeSensor* s, RangeSensor* a);
};

#endif
