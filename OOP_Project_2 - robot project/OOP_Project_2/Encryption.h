/**
 * @file Encryption.h
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief  Header file of class that encrypt and decrypt.
 */
#ifndef	ENCRYPTÝON_H
#define ENCRYPTÝON_H

using namespace std;
//! A class to encrypt and decrypt the given code.
/*!
 This class findes encrypted and decrypted verison of given codes.
*/
class Encryption {
public:
    /** \brief function for encrypt code.
      * \param abcd is int argument to represent code.
      * \return encrypted code.
     */
	int encrypt(int abcd);
    /** \brief function for decrypt code.
      * \param cdab is int argument to represent encrypted code.
      * \return decrypted code.
     */
	int decrypt(int cdab);
};
#endif;