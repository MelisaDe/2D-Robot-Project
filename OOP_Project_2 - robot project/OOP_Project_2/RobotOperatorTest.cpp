/**
 * @file RobotOperatorTest.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  Test source file of class that will be used to test RobotOperator class.
 */
#include<iostream>
#include<stdlib.h>
#include "Encryption.h"
#include "RobotOperator.h"
using namespace std;
///Main function to create RobotOperator objects and use function of RobotOperator class.
int main() {
	RobotOperator r(4322);
	r.set_name("John");
	r.set_surname("Doe");
	if(r.checkAccessCode(1890)){
		cout << "Access Code and encrypted code is match." << endl;
	}
	else{
		cout << "Access Code and encrypted code is not match." << endl;
	}
	cout << "User's data printing with print function..." << endl;
	r.print();

	RobotOperator t(5487);
	t.set_name("Jane");
	t.set_surname("Doe");
	if(t.checkAccessCode(5421)){
		cout << "Access Code and encrypted code is match." << endl;
	}
	else{
		cout << "Access Code and encrypted code is not match." << endl;
	}
	cout << "User's data printing with print function..." << endl;
	t.print();

	cout<<"1456's encrypted version is: "<< t.encryptCode(1456)<<endl;
	cout << "3574's decrypted version is: " << t.decryptCode(3574)<<endl;


	system("pause");
}