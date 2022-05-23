/**
 * @file RobotOperator.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  Source file of class that will be used to authorize the operator
 *        that will command the robot for use in Robot applications.
 */
#include"RobotOperator.h"
#include"Encryption.h"

RobotOperator::RobotOperator(int accessCode) {
    this->accessCode = encryptCode(accessCode);
}
void RobotOperator::set_name(string name) {
    this->name = name;
}
string RobotOperator::get_name() {
    return name;
}
string RobotOperator::get_surname() {
    return surname;
}
void RobotOperator::set_surname(string surname) {
    this->surname = surname;
}
//function for encrypt code with using Encryption class' function.
int RobotOperator::encryptCode(int num) {
    Encryption e; 
    return  e.encrypt(num);
}
//function for decrypt code with using Encryption class' function.
int RobotOperator::decryptCode(int num) {
    Encryption e; 
    return e.decrypt(num);
}
//brief checks whether the entered code is the same as accesscode, which is kept encrypted.
bool RobotOperator::checkAccessCode(int num) {
    if (accessCode == num){
        accessState=true;
	}
    else {
        accessState = false;
    }
    
    return accessState;
}

 //brief prints the operator's name, surname, and access status.
void RobotOperator::print() {
   cout << "Name: " << name << endl;
   cout << "Surname: " << surname << endl;
   if (accessState)
   {
       cout << "Access state: Success " << endl;
   }
   else {
       cout << "Access state: Unsuccess " << endl;
   }
}



