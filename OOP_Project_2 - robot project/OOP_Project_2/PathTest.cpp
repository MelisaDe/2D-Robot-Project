/**
 * @file PathTest.cpp
 * @Author Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  Test source file of class that stores and organizes the poses .
 */
#include <iostream>
#include"Pose.h"
#include"Path.h"
using namespace std;

Path path;/*!< path is created path type object. */
Pose pose; /*!< path is created path type object. */
Pose t;/*!< path is created path type object. */

///Main function to call pose and path classes objects.
int main() {
	pose.setPose(100, 200, 30);
	path.addPos(pose);

	pose.setPose(150, 170, 50);
	path.addPos(pose);

	pose.setPose(130, 180, -10);
	path.addPos(pose);

	cout << "Print path with print function: " << endl;
	path.print();

	pose = path.getPos(1);
	cout << "Print path with operator overloading: " << endl;
	cout << path;

	t.setPose(20, 30, 90);
	cout << "Inserting new pose at given index.." << endl;
	path.insertPos(1, t);
	path.print();
	cout << "Enter the coordinates and angle of new pose to add this at the end of the path." << endl;
	cin >> path;
	cout << "Inserting new pose at the end of the path with using operator overloading.." << endl;
	path.print();
	cout << "Deleting  pose at the given position from path.." << endl;
	path.removePos(3);
	path.print();
	return 0;

};