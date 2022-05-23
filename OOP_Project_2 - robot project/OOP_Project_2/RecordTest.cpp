/**
 * @file RecordTest.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Test source file of  a class that will be used to test Record class.
 */
#include<iostream>
#include<stdlib.h>
#include <string>
#include"Record.h"
using namespace std;
Record r;/*!< r is created  as record type object.*/
///Main function to create Record objects and use function of Record class.
int main() {

	r.setFileName("input.txt","output.txt");
	if (!r.open_input_File()) {
		cout << "Input file open ERROR!" << endl;
		exit(0);
	}
	if (!r.open_output_File()) {
		cout << "Output file open ERROR!" << endl;
		exit(0);
	}
	cout <<"Data that reading from file: " <<r.readLine()<<endl;
	r.writeLine("deneme_1");
	r.writeLine("deneme_2");
	r.writeLine("deneme_3");
	r.set_name(r.readLine());
	r.set_surname(r.readLine());
	r.writeLine(r.get_name());
	r.writeLine(r.get_surname());
	r.writeLine(to_string(r.encryptCode(stoi(r.readLine()))));

	if (!r.close_input_File()) {
		cout << "Input file close ERROR!" << endl;
	}
	if (!r.close_output_File()) {
		cout << "Output file close ERROR!" << endl;
	}
	return 0;
}