/**
 * @file Pose.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  Source file of class that take poses and compare them.
 */
#include"Pose.h"

//set x coordinate.
void Pose::setX(float X)
{
	x = X;
}
float Pose::getX()
{
	return x;
}
//set y coordinate.
void Pose::setY(float Y)
{
	y= Y;
}
float Pose::getY()
{
	return y;
}
//set y coordinate.
void Pose::setTh(float TH)
{
	th = TH;
}

float Pose::getTh()
{
	return th;
}
//control given 2 pose is equal or not
bool Pose::operator ==(const Pose& other)
{
	return(x == other.x && y == other.y && th == other.th);
}
//sum of 2 pose and attemp them new pose
Pose Pose:: operator +(const Pose& other)
{
	Pose result;
	result.x = x + other.x;
	result.y = y + other.y;
	result.th = th + other.th;
	return result;
}
//difference of 2 pose and attemp them new pose
Pose Pose:: operator -(const Pose& other)
{
	Pose result;
	result.x = x - other.x;
	result.y = y - other.y;
	result.th = th - other.th;
	return result;
}
//sum of 2 pose but first pose take new values.
Pose& Pose::operator +=(const Pose& other)
{
	this->x += other.x;
	this->y += other.y;
	this->th += other.th;
	return *this;
}
// differece of 2 pose but first pose take new values.
Pose& Pose::operator -=(const Pose& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->th -= other.th;
	return *this;
}
//function for compare is first pose smaller than second pose
bool Pose::operator<(const Pose& other)
{
	return(x < other.x && y < other.y && th < other.th);
}

Pose& Pose::getPose() {
	return *this;
}
//function for set new pose.
void Pose::setPose(float _x, float _y, float _th)
{
	x = _x;
	y = _y;
	th = _th;
}
//function for find distance between 2 pose.
float Pose::findDistanceTo(Pose pos)
{
	float d,x_,y_;
	x_ = (x - pos.x) * (x - pos.x);
	y_ = (y - pos.y) * (y - pos.y);
	d = sqrt(x_ + y_);
	return d;
}
//function for find angle between 2 pose.
float Pose::findAngleTo(Pose pos)
{
	float teta;
	teta = ((y - pos.y) / (x - pos.x));
	float angle = atan(teta) * 180 / PI;
	return angle;
}