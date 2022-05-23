/**
 * @file SonarSensor.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com)
 * @date January, 2021
 * @brief Source file of class that stores the sonar sensor's datas.
 */
#include<iostream>
#include "PioneerRobotAPI.h"
#include"SonarSensor.h"

using namespace std;
//get asked range's data.
float SonarSensor::getRange(int index) {
	return ranges[index];
}
//find maxiumum range.
float SonarSensor::getMax(int& index) {
	float max;
	int max_in = 0;
	max = ranges[0];
	for (int i = 0; i < 16; i++)
	{
		if (ranges[i] > max) {
			max = ranges[i];
			max_in = i;
		}
	}
	index = max_in;
	return index;
}
//find minimum range.
float SonarSensor::getMin(int& index) {
	int min;
	min = 0;
	for (int i = 0; i < 16; i++)
	{
		min = ranges[i] < ranges[min] ? i : min;
	}
	index = min;
	return index;
}
//updating sonar ranges according to robot's moves.
void SonarSensor::updateSensor(float ranges[]) {
	//ranges array determined with datas getting from PioneerRobotAPI.
	for (int i = 0; i < 16; i++)
	{
		this->ranges[i] = ranges[i];
	}
}
// get angle of asked index.
float SonarSensor::getAngle(int index) {
	//angles are determined according to circle and  x-y coordinates.
	float angle[16] = { 90,50,30,10,0,-10,-30,-50,-90,230,210,190,180,170,150,130 };
	return angle[index];
}
float SonarSensor::getClosestRange(float startAngle, float endAngle, float& angle) {
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
float SonarSensor::operator [](int i) {
	return ranges[i];
}