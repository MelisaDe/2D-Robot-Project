/**
 * @file RobotOperator.h
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  It is a class that will be used to authorize the operator
 *        that will command the robot for use in Robot applications.
 */
#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
//! A class to stored user's infos.
/*!
 This class is store name, surname and control encrypted/decrypted code.
*/
class RobotOperator {

private:
	string name; /*!< name is string type variable to represent user' name. */
	string surname; /*!< surname is string type variable to represent user' surname. */
	unsigned int accessCode; /*!< accessCode is unsigned int type variable to represent Access Code. */
	bool accessState; /*!< x is float type variable to represent Access State. */
public:
	RobotOperator(){}
	RobotOperator(int accesCode);
	/** \brief function set user's name
       * \param name is string to represent user name.
     */ 
	void set_name(string);
	/** \brief function set user's surname
       * \param name is string to represent user surname.
     */ 
	void set_surname(string);
	/** \brief function for get user's name
      * \return name
     */
	string get_name();
	/** \brief function for get user's surname
      * \return surname
     */
	string get_surname();
	/** \brief function for encrypt code with using Encryption class' function.
       * \param num is int to represent given code.
      * \return encrypted code
     */
	int encryptCode(int);
	/** \brief function for decrypt code with using Encryption class' function.
       * \param num is int to represent given code.
      * \return decrypted code
     */
	int decryptCode(int);
    /** \brief function for checking entered code and acces code is equal or not.
       * \param num is int to represent entered code.
      * \return true or false
     */
	bool checkAccessCode(int);
	/** \brief function for print user's datas.
     */
	void print();
};
#endif;