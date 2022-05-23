/**
 * @file Path.h
 * @Author Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Header file of class that stores and organizes the poses .
 */
#ifndef PATH_H
#define PATH_H
#include <iostream>
#include"Node.h"
#include"Pose.h"
using namespace std;
 //! A class to stores  and organizes the poses.
 /*!
  This class addes,removes,inserts and prints poses.
 */

class Path {
	
private:
	
public:
    Node* tail;/*!< tail is created as Node* type object to represent take the end of the path. */
    Node* head;/*!< head is created as Node* type object to represent take the start of the path. */
    static int number;/*!< number is static int type variable to represent number of path's node. */
	/** \brief class' constructor
     */
	Path();
	/** \brief function for add node at the end of the path.
      * \param pose is Pose argument to represent data of new node.
     */
	void addPos(Pose pose);
	/** \brief function for print path' datas.
     */
	void print();
	/** \brief function for get pose which in asked index.
      * \param index is int argument to represent index of asked pose.
      * \return pose of given index
     */
	Pose& operator[](int index);
	/** \brief function for get pose.
      * \param index is int argument to represent index of asked pose.
      * \return pose of given index.
     */
	Pose getPos(int index);
    /** \brief function for remove pose at the given index from path.
      * \param index is int argument to represent index of asked pose.
     */
	void removePos(int index);
    /** \brief function for insert pose to path at given index..
      * \param index is int argument to represent index of inserting pose.
      * \param pose is pose argument to represent position.
     */
	void insertPos(int index, Pose pose);
     /** \brief function for print path' datas with using operator overloading.
      * \param output is ostream& argument to represent print datas.
      * \param d is Path& argument to represent path.
      * \return output
     */
	friend ostream& operator << (ostream& output, const Path& d);
    /** \brief function for add new node at the end of the path with using operator overloading.
      * \param Read is istream& argument to represent take datas.
      * \param d is Path& argument to represent path.
      * \return Read
     */
	friend istream& operator >> (istream& Read, Path& d);
	
};
#endif