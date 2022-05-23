/**
 * @file Node.h
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  Header file of class that Node.
 */
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Pose.h"

using namespace std;

//! A class to create node.
/*!
	A class that take node's.
*/
class Node {
public:
	Node* next; /*!< next is Node* type object. */
	Pose pose; /*!< pose is Pose type object. */
};
#endif