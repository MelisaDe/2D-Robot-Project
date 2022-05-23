/**
 * @file SonarSensor.h
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com)
 * @date January, 2021
 * @brief Header file of class that stores the sonar sensor's datas.
 */
#ifndef SONARSENSOR_H
#define SONARSENSOR_H
#include<iostream>
#include "PioneerRobotAPI.h"
#include "RangeSensor.h"
using namespace std;
//! A class to stores the sonar sensor's datas.
/*!
 This class findes min,max ranges and angle.Inherited based on PioneerRobotAPI.
*/
class SonarSensor : public RangeSensor {
public:
    /** \brief function for get asked range's data.
     * \param index is int argument to represent index of asked range.
     * \return ranges[index]
    */
    float getRange(int index);
    /** \brief function for find maxiumum range.
     * \param index is int argument to represent index of stored maximum range.
     * \return index of maximum range.
    */
    float getMax(int& index);
    /** \brief function for find minimum range.
     * \param index is int argument to represent index of stored minimum range.
     * \return index of minimum range.
    */
    float getMin(int& index);
    /** \brief function for updating ranges according to robot's move.
     * \param ranges float array to represent ranges of solar sensors.
    */
    void updateSensor(float ranges[]);
    /** \brief function to get angle of asked index.
     * \param index is int argument to represent asked index.
     * \return angle of given index.
    */
    float getAngle(int index);
    float operator[](int i);
    float getClosestRange(float startAngle, float endAngle, float& angle);
};
#endif