/**
 * @file Path.cpp
 * @Author Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Source file of class that stores and organizes the poses .
 */
#include"Node.h"
#include"Pose.h"
#include"Path.h"
using namespace std;
int Path::number = 0;
Path::Path() {
    head = NULL;
}
//add node at the end of the path.
void Path::addPos(Pose pose){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->pose = pose;
  
    if (head == NULL) {
        
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else {
       
        tail->next = newNode;
        tail = newNode;  
        tail->next = NULL; 
    }

    number++;
}
// print path' datas.
void Path::print(){
    Node* p = head;
    while (p != NULL) {
        cout << p->pose.getX() << " " << p->pose.getY() << " " << p->pose.getTh() << endl;
        p = p->next;
    }
}
//get pose which in asked index
Pose& Path::operator[](int index) {
    Node* current = head;
    int temp = 1;

    while (temp <= index) {
        if (index == temp) {
            return current->pose;
        }
        else
        {
            current = current->next;
        }
        temp++;
    }
}
Pose Path::getPos(int index){
    Node* current = head;
      int temp = 1;   
    while (temp <= index) {
        if (index == temp) {
            return current->pose;        
        }
        else
        {
            current = current->next;
        }
        temp++;
    }
}
//remove pose at the given index from path.
void Path::removePos(int index){
        int count = 0;
        Node* temp, * temp1, * temp2;
        temp = head;
        if (head == NULL) {
            return;
        }
        else if (index == 0)
        {
            head = head->next;
            free(temp);
        }
        else if (index == number) {
            while (head->next != tail) {
                head = head->next;
            }
            tail = head;
            delete tail->next;
        }
        else {
            while (count != index-1 )
            {
                temp = temp->next;
                count++;
            }
            temp1 = temp->next;
            temp->next = temp1->next;

            free(temp1);
        }
        number--;

}
//insert pose to path at given index..
void Path::insertPos(int index, Pose pose){
    Node* add = new Node;
    add->pose = pose;
    add->next = NULL;

    if (head == NULL)
        head = add;
    else if (index == 0)
    {
        add->next = head;
        head = add;
    }
    else if (index == number) {
        addPos(pose);
    }
    else
    {
        Node* cur = head;
        int d = 1;
        while (cur != NULL)
        {
            if (d == index)
            {
                add->next = cur->next;
                cur->next = add;
                break;
            }
            cur = cur->next;
            d++;
        }
    }
    number++;
}
//print path' datas with using operator overloading.
ostream &operator << (ostream &output, const Path& a) {
    Path b = a;
    while (b.head != NULL) {
        output << b.head->pose.getX() << " " << b.head->pose.getY() << " " << b.head->pose.getTh() << endl;
        b.head = b.head->next;
    }
    return output;
}
//add new node at the end of the path with using operator overloading.
istream& operator >>(istream& Read, Path& d)
{
    float x, y, th;
    Pose p;
    cout << "Enter the x coordinate of the now pose: ";
    Read >> x;  
    cout<<"Enter the y coordinate of the new pose: ";
    Read >> y;
    cout<<"Enter the angle of the new pose: ";
    Read >> th;
    p.setX(x);
    p.setY(y);
    p.setTh(th);

    d.addPos(p);
    return Read;
}
