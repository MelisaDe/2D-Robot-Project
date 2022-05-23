/**
 * @file Pose.h
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  Header file of class that take poses and compare them.
 */
#ifndef POSE_H
#define POSE_H
#include <iostream>
#include <iostream>
#include <math.h>
#define PI 3.14159265

using namespace std;
//! A pose class to read and write x y coodinate and angle datas .
/*!
	This class to read and write x y coodinate and angle datas  and find distance and angle between two pose.
*/
class Pose {
private:
	float x;/*!< x is float type variable to represent x coordinate. */
	float y;/*!< y is float type variable to represent y coordinate. */
	float th;/*!< th is float type variable to represent angle. */
public:
	/** \brief set x coordinate.
      * \param X represent to x coordinate
     */
	void setX(float);
    /*\return x
     */
	float getX();
	/** \brief set y coordinate.
      * \param Y represent to y coordinate
     */
	void setY(float);
    /*\return y
     */
	float getY();
	/** \brief set y coordinate.
      * \param TH represent to Th angle.
     */
	void setTh(float);
    /*\return th
     */
	float getTh();

	/** \brief control given 2 pose is equal or not
      * \param other is Pose& object to represent given pose.
      * \return true or false
     */
	bool operator ==(const Pose& other);
	/** \brief function for sum of 2 pose and attemp them new pose
       * \param other is Pose& object to represent given pose.
      * \return new pose
     */
	Pose operator +(const Pose& other);
	/** \brief function for difference of 2 pose and attemp them new pose
       * \param other is Pose& object to represent given pose.
      * \return new pose
     */
	Pose operator -(const Pose& other);
	/** \brief function for sum of 2 pose but first pose take new values.
       * \param other is Pose& object to represent given pose.
      * \return first pose.
     */
    Pose& operator +=(const Pose& other);
	/** \brief function for differece of 2 pose but first pose take new values.
       * \param other is Pose& object to represent given pose.
      * \return first pose.
     */
	Pose &operator -=(const Pose& other);
	/** \brief function for compare is first pose smaller than second pose. 
       * \param other is Pose& object to represent given pose.
      * \return true or false
     */
	bool operator <(const Pose& other);

    /** \return pose
     */
	Pose& getPose();
	/** \brief function for set new pose.
      * \param _x is float argument to represent x coordinate
      * \param _y is float argument represent to y coordinate
      * \param _th is float argument represent to Th angle.
     */
	void setPose(float _x, float _y, float _th);
	/** \brief function for find distance between 2 pose.
      * \param pos is Pose argument to represent given pose.
      * \return distance
     */
	float findDistanceTo(Pose pos);
	/** \brief function for find angle between 2 pose.
      * \param pos is Pose argument to represent given pose.
      * \return angle
     */
	float findAngleTo(Pose pos);
};
#endif