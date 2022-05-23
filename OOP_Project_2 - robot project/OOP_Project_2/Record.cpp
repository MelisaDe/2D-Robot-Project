/**
 * @file Record.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  Source file performs file saving operations
 *         for use in Robot applications.
 */
#include <iostream>
#include <fstream>
#include <string>
#include "Record.h"
#include"RobotOperator.h"

//Open the input file.
bool Record::open_input_File(){
	input.open(inputfileName);
	if (!input) {
		return false;
	}
	return true;
}
//Close the input file.
bool Record::close_input_File() {
	input.close();
	if(input.is_open()){
		return false;
	}
	return true;
}
//Open the output file.
bool Record::open_output_File(){
   output.open(outputfileName);
	if (!output) {
		return false;
	}
	return true;
}
//Close the output file.
bool Record::close_output_File() {
	output.close();
	if(output.is_open()){
		return false;
	}
	return true;
}
//set files name
void Record::setFileName(string inName,string outName) {
	inputfileName = inName;
	outputfileName = outName;
}
//read datas from input file.
string Record ::readLine() {
	string s = "";
	getline(input, s);
	return s;
}
//write datas to output file.
void Record::writeLine(string str){
	output <<str<<endl;
}
