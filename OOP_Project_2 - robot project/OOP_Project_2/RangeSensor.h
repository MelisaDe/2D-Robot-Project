/**
 * @file LaserSensor.h
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com)
 * @date January, 2021
 * @brief  Header file of class that stores the laser ranges's datas.
 */

#ifndef RANGESENSOR_H
#define RANGESENSOR_H
#include<iostream>

using namespace std;
//! A class to stores the laser sensor's datas.
/*!
 This class findes min,max and closest ranges and angle.
*/
class RangeSensor{
public:
   
    float ranges[1000]; /*!< ranges is created float type array to store laser sensor datas. */
    /** \brief function for get asked range's data.
      * \param index is int argument to represent index of asked range.
      * \return range of given index
     */
    virtual float getRange(int index) = 0;
    /** \brief function for updating ranges.
      * \param ranges float array to represent ranges of solar sensors.
     */
    virtual void updateSensor(float ranges[]) = 0;
    /** \brief function for find maxiumum range.
      * \param index is int argument to represent index of stored maximum range.
      * \return index of maximum range.
     */
    virtual float getMax(int& index) = 0;
    /** \brief function for find minimum range.
      * \param index is int argument to represent index of stored minimum range.
      * \return index of minimum range.
     */
    virtual float getMin(int& index) = 0;
    /** \brief function for overloading index.
     * \param i int argument to represent index.
    * \return range of given index.
    */
    virtual float operator[](int i) = 0;
    /** \brief function to get angle of asked index.
      * \param index is int argument to represent asked index.
      * \return angle of given index.
     */
    virtual float getAngle(int index) = 0;
    /** \brief function for find minimum range between startAngle and endAngle.
      * \param startAngle is float argument to represent start point.
      * \param endAngle is float argument to represent end point.
      * \param angle is float argument to represent angle of minimum range.
      * \return minimum range.
     */
    virtual float getClosestRange(float startAngle, float endAngle, float& angle) = 0;
};
#endif
