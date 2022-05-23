/**
 * @file Menu.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Header file of class that control robot's all situations.
 */
#ifndef MENU_H
#define MENU_H
#include "RobotControl.h"
#include"Pose.h"
 //! A class to display menu.
 /*!
  This class display menu and calling function according to input that prompt from user.
 */
class Menu {
private:
    bool connection_control; /*!< connected_control is created bool type object to represent robot's connect situation. */
    static int move_distance;/*!< move_distance is created static int type variable to represent robot's distance covered. */
    //RobotControl robot;/*!< robot is created RobotControl type object. */
public:
    RangeSensor* sens = new SonarSensor;
    RangeSensor* sens1 = new LaserSensor;
    RobotInterface* piooner = new PioneerRobotInterface;
    Pose p;
    RobotControl* robot;
    Menu();
    ~Menu();
    /** \brief function for display main menu.M
     */
    void display();
    /** \brief function for control robot's connect situation.
     */
    void connection();
    /** \brief function for control robot's moves.
     */
    void motion();
    /** \brief function for control sensors' datas.
     */
    void sensor();
    /** \brief function for exit from program.
     */
    void Quit();
    void access(int);

};

#endif;