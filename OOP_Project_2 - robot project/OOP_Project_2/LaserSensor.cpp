/**
 * @file LaserSensor.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com)
 * @date January, 2021
 * @brief  Source file of class that stores the laser ranges's datas.
 */
#include<iostream>
#include"LaserSensor.h"

using namespace std;
// get asked range's data.
float LaserSensor::getRange(int index) {
	return ranges[index];
}
//find maximum range.
float LaserSensor::getMax(int& index) {
	int max;
	max = 0;
	for (int i = 0; i <= 181; i++)
	{
		max = ranges[i] > ranges[max] ? i : max;
	}
	index = max;
	return index;

}
//find minimum range.
float LaserSensor::getMin(int& index) {
	int min;
	min = 0;
	for (int i = 0; i <= 181; i++)
	{
		min = ranges[i] < ranges[min] ? i : min;
	}
	index = min;
	return index;
}
//updating  laser ranges according to robot's move..
void LaserSensor::updateSensor(float ranges[]) {
	// laser ranges array determined with datas getting from PioneerRobotAPI.
	for (int i = 0; i <= 181; i++)
	{
		this->ranges[i] = ranges[i];
	}
}
//get angle of asked index.
float LaserSensor::getAngle(int index) {
	return index;
}
//find minimum range between startAngle and endAngle.
float LaserSensor::getClosestRange(float startAngle, float endAngle, float& angle) {
	int min_index = startAngle;
	float min = ranges[min_index];
	for (int i = startAngle; i <= endAngle; i++)
	{
		if (ranges[i] < min) {
			min = ranges[i];
			min_index = i;
		}
	}
	angle = min_index;
	return ranges[min_index];
}
float LaserSensor::operator [](int i) {
	return ranges[i];
}