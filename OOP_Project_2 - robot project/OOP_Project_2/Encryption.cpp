/**
 * @file Encryption.cpp
 * @Author 
 * @date January, 2021
 * @brief  Source file of class that encrypt and decrypt.
 */

#include<iostream>
#include"Encryption.h"
//encrypt to code
int Encryption::encrypt(int abcd){
	int result, a, b, c, d;

	a = abcd / 1000;
	a += 7;
	a = a % 10;

	abcd = abcd % 1000;

	b = abcd / 100;
	b += 7;
	b = b % 10;

	abcd = abcd % 100;

	c = abcd / 10;
	c += 7;
	c = c % 10;

	abcd = abcd % 10;

	d = abcd;
	d += 7;
	d = d % 10;

	result = (c * 1000) + (d * 100) + (a * 10) + (b * 1);
	return result;
}
//decrypt to code.
int Encryption::decrypt(int cdab){
	int result, a, b, c, d;
	c = cdab / 1000;
	c = (c + 3) % 10;

	cdab = cdab % 1000;

	d = cdab / 100;
	d= (d + 3) % 10;

	cdab = cdab % 100;

	a = cdab / 10;
	a = (a + 3) % 10;

	cdab = cdab % 10;

	b= cdab;
	b = (b + 3) % 10;

	result = (a * 1000) + (b * 100) + (c * 10) + (d * 1);
	return result;
	
}