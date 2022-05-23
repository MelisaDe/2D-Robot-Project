/**
 * @file RobotControl.h
 * @Author Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Header file of class that controlling the robot's moves.
 */

#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H
#include"Node.h"
#include"Pose.h"
#include"RangeSensor.h"
#include"SonarSensor.h"
#include"LaserSensor.h"

 //! A class to controlling robot.
 /*!
  This class controlling the robot's moves and stores Pose datas.
 */
class RobotInterface {
protected:

    Pose* position;/*!< position is created Pose type object. */
    RangeSensor* rangeSensorS;
    RangeSensor* rangeSensorL;
    
public:
    int state;
    virtual bool connectRobot() = 0;
    virtual void disconnectRobot() = 0;
    virtual void setSensors(RangeSensor* s, RangeSensor* a) = 0;
    /** \brief function for turning robot to left.
     */
    virtual void turnLeft() = 0;
    /** \brief function for turning robot to right.
     */
    virtual void turnRight() = 0;
    /** \brief function for moving robot forward.
      * \param speed_ is float argument to represent speed of robot.
     */
    virtual void forward_(float speed) = 0;
    /** \brief function for print position's datas.
     */
    virtual void print() = 0;
    /** \brief function for moving robot backward.
      * \param speed_ is float argument to represent speed of robot.
      */
    virtual void backward(float speed) = 0;
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
    virtual void stopTurn() = 0;
    /** \brief function for stop robot's move.
     */
    virtual void stopMove() = 0;

    virtual void updateSensors() = 0;
    virtual void updaterobot() = 0;
    /*  virtual ~RobotInterface() = 0;*/

};

#endif

