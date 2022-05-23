/**
 * @file Record.h
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  It performs file saving operations
 *         for use in Robot applications. 
 */
#ifndef RECORD_H
#define RECORD_H
#include<iostream>
#include<string>
#include <fstream>
#include"RobotOperator.h"

using namespace std;
//! A class to read input from file and write to output file.
/*!
 This class open and close input and output files ,reading datas from input file and writing datas t output file.
*/
class Record:public RobotOperator {
private:
	string inputfileName;/*!< inputfileName is created  as string type variable.*/
	string outputfileName;/*!< outputfilename is created  as string type variable. */
	ifstream input;/*!< input is created  as ifstream type variable. */
	ofstream output;/*!< output is created as oftream type variable. */
public:
	/** \brief Open the input file.
	  * \return true false
	 */
	bool open_input_File();
	/** \brief Close the input file.
	  * \return true or false
	 */
    bool close_input_File();
	/** \brief Open the output file.
	  * \return true or false
	 */
	bool open_output_File();
	/** \brief Close the output file.
	  * \return true or false
	 */
	bool close_output_File();
	/** \brief set files name 
	  * \param inName is string to represent input file name.
	  * \param outName is string to represent output file name.
	 */
	void setFileName(string inName,string outName);
	/** \brief read datas from input file.
	  * \return string type read data.
	 */
	string readLine();
	/** \brief write datas to output file.
	  * \param str is string to represent read data..
	 */
	void writeLine(string str);
};
#endif;



