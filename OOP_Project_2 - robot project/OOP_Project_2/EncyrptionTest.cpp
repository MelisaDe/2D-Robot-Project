/**
 * @file EncryptionTest.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Test file of class that encrypt and decrypt.
 */
#include"Encryption.h"
#include<iostream>
///Main function to create a Encryption object and call the functions of Encryption.
int main()
{
	Encryption e1;

	cout << "Value: 5641 " << endl << "Encrypted value: " << e1.encrypt(5641) << endl;
	cout << "-------------------------------------" << endl;

	cout << "Encrypted value: 1823" << endl << "Decrypted value: " << e1.decrypt(1823) << endl;
	cout << "-------------------------------------" << endl;


	cout << "Value: 9658 " << endl << "Encrypted value: " << e1.encrypt(9658) << endl;
	cout << "-------------------------------------" << endl;

	cout << "Encrypted value: 2563" << endl << "Decrypted value: " << e1.decrypt(2563) << endl;
	cout << "-------------------------------------" << endl;


	return 0;
}