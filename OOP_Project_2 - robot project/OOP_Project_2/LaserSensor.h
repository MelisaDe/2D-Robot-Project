/**
 * @file LaserSensor.h
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com)
 * @date January, 2021
 * @brief  Header file of class that stores the laser ranges's datas.
 */

#ifndef LASERSENSOR_H
#define LASERSENSOR_H
#include<iostream>
#include"RangeSensor.h"


using namespace std;
//! A class to stores the laser sensor's datas.
/*!
 This class findes min,max and closest ranges and angle.
*/
class LaserSensor : public RangeSensor {
public:
    /** \brief function for get asked range's data.
      * \param index is int argument to represent index of asked range.
      * \return range of given index
     */
    float getRange(int index);
    /** \brief function for updating ranges.
      * \param ranges float array to represent ranges of solar sensors.
     */
    void updateSensor(float ranges[]);
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
    /** \brief function to get angle of asked index.
      * \param index is int argument to represent asked index.
      * \return angle of given index.
     */
    float getAngle(int index);
    /** \brief function for find minimum range between startAngle and endAngle.
      * \param startAngle is float argument to represent start point.
      * \param endAngle is float argument to represent end point.
      * \param angle is float argument to represent angle of minimum range.
      * \return minimum range.
     */
    float operator [](int i);
    float getClosestRange(float startAngle, float endAngle, float& angle);
};
#endif
