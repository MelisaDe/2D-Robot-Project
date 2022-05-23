/**
 * @file Menu.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Source file of class that control robot's all situations.
 */
#include <iostream>
#include "Menu.h"
#include "RobotControl.h"
#define T 2 //robot's move second.

int b = 0;
int Menu::move_distance = 0;

Menu::Menu() { robot = new RobotControl(piooner, sens, sens1, &p); connection_control = false; }
Menu::~Menu() { robot->disconnectRobot(); delete sens, sens1, piooner, robot; }

//display main menu.
void Menu::display() {
    int a, code;

    cout << "Main Menu" << endl;
    cout << "1. Connection" << endl;
    cout << "2. Motion" << endl;
    cout << "3. Sensor" << endl;
    cout << "4. Quit" << endl;
    cout << "5. Access" << endl;
    cout << "Choose one: ";
    cin >> a;
    //chosen with user's input.
    switch (a) {
    case 1:
        connection();
        break;
    case 2:
        if (!connection_control)//if robot is not connected, user cannot go to motion menu.
        {
            cout << "ERROR! Robot is not connected. Please connect robot first." << endl;
            display();
        }
        motion();
        break;
    case 3:
        if (!connection_control)//if robot is not connected, user cannot go to sensor menu.
        {
            cout << "ERROR! Robot is not connected. Please connect robot first." << endl;
            display();
        }
        sensor();
        break;
    case 4:
        Quit();
        break;
    case 5:
        cout << "Enter access code: ";
        cin >> code;
        access(code);
    default:
        cout << "ERROR! Unvalid Entry." << endl << endl;
        break;
    }
}
void Menu::access(int code) {
    int a;
    cout << "Access Menu" << endl;
    cout << "1. Open Access" << endl;
    cout << "2. Close Access " << endl;
    cout << "3. Back " << endl;
    cout << "4. Quit " << endl;
    cout << "Choose one: ";
    cin >> a;//prompt from user.

    switch (a) {
    case 1:
        if (robot->openAccess(code)) {
            cout << "<Open Access>" << endl;
            robot->access_control = true;
            cout << "Robot is open to access... " << endl << endl;
        }
        else {
            cout << "Wrong Access code... " << endl << endl;
            display();
        }
        break;
    case 2:
        if (robot->closeAccess(code)) {
            cout << "<Close Access>" << endl;
            robot->access_control = false;
            cout << "Robot is close to access..." << endl << endl;
        }
        else {
            cout << "Wrong Access Code...." << endl << endl;
            display();
        }
        break;
    case 3:
        display();
        break;
    case 4:
        Quit();
        break;
    default:
        cout << "ERROR! Unvalid Entry." << endl << endl;
        break;
    }
    display();
}
//function for control robot's connect situation.
void Menu::connection() {
    int a;
    cout << "Connection Menu" << endl;
    cout << "1. Connect Robot " << endl;
    cout << "2. Disconnect Robot " << endl;
    cout << "3. Back " << endl;
    cout << "4. Quit " << endl;
    cout << "Choose one: ";
    cin >> a;//prompt from user.

    //chosen with user's input.
    switch (a) {
    case 1:
        robot->connectRobot();
        if (robot->access_control) {
            connection_control = true;
            cout << "<Connect>" << endl;
            cout << "Robot is connected... " << endl << endl;
        }
        break;
    case 2:
        if (!connection_control)
        {
            cout << "ERROR! There is not any connected robot. Please connect first." << endl;
            connection();
        }
        else {
            robot->disconnectRobot();
            if (robot->access_control) {
                connection_control = false;
                cout << "<Disconnect>" << endl;
                cout << "Robot is disconnected..." << endl << endl;
                exit(0);
            }
        }
        break;
    case 3:
        display();
        break;
    case 4:
        Quit();
        break;
    default:
        cout << "ERROR! Unvalid Entry." << endl << endl;
        break;
    }
    connection();
}
//function for control robot's moves.
void Menu::motion() {

    int a;
    cout << "Motion Menu" << endl;
    cout << "1. Move robot" << endl;
    cout << "2. Safe Move Robot" << endl;
    cout << "3. Turn left" << endl;
    cout << "4. Turn Right" << endl;
    cout << "5. Stop Turn" << endl;
    cout << "6. Move distance" << endl;
    cout << "7. Stop Move" << endl;
    cout << "8. Back" << endl;
    cout << "9. Quit" << endl;
    cout << "Choose one: ";
    cin >> a;//prompt from user.

    //chosen with user's input.
    switch (a) {
    case 1:
        //robot is moving  until entered stopTurn option.
        cout << "Enter the speed: ";
        cin >> b;

        if (b > 0) { robot->forward_(b); }
        else { b *= -1; robot->backward(b); } //if user entered negative speed, robot moving back.
        if (robot->access_control) {
            move_distance += b * T;
            Sleep(1000);
            cout << "<Moving>" << endl;
            cout << "Robot is moving with " << b << " speed..." << endl << endl;
        }
        break;
    case 2:
        if (robot->access_control) {
            //the last motion of the robot is continued in the same way.
            if (robot->robotinterface->state) {
                Sleep(1000);
                move_distance += b * T;
                cout << "Robot is save move." << endl;
            }

        }
        break;
    case 3:
        //robot is turning to left until entered stopTurn option.
        robot->turnLeft();
        if (robot->access_control) {
            if (robot->robotinterface->state) { move_distance += b * T; }
            Sleep(1000);
            cout << "<Turning to left>" << endl;
            cout << "Robot is turning to left..." << endl << endl;
        }
        break;
    case 4:
        //robot is turning to right until entered stopTurn option.
        robot->turnRight();
        if (robot->access_control) {
            if (robot->robotinterface->state) { move_distance += b * T; }
            Sleep(1000);
            cout << "<Turning to right>" << endl;
            cout << "Robot is turning to right..." << endl << endl;
        }
        break;
    case 5:
        robot->stopTurn();
        if (robot->access_control) {
            Sleep(1000);
            b = 0;
            cout << "<Stop Turn>" << endl;
            cout << "Robot is stopped turn..." << endl << endl;
        }
        break;
    case 6:
        //distance covered of robot is print.
        cout << "Move distance: " << move_distance << endl;
        break;
    case 7:
        robot->stopMove();
        if (robot->access_control) {
            cout << "<Stop Move>" << endl;
            cout << "Robot is stopped move..." << endl << endl;
        }
        break;
    case 8:
        display();
        break;
    case 9:
        Quit();
        break;
    default:
        cout << "ERROR! Unvalid Entry." << endl << endl;
        break;
    }
    motion();
}
////brief function for control sensors' datas.
void Menu::sensor() {
    int a;
    cout << "Sensor Menu" << endl;
    cout << "1. Laser Datas " << endl;
    cout << "2. Sonar Datas " << endl;
    cout << "3. Back " << endl;
    cout << "4. Quit " << endl;
    cout << "Choose one: ";
    cin >> a;//prompt from user.

     //chosen with user's input.
    switch (a) {
    case 1:
        if (robot->access_control) {
            cout << "<Laser Datas>" << endl;
            cout << "Laser ranges are [ ";
            robot->robotinterface->updateSensors();
            for (int i = 0; i < 181; i++) {
                cout << robot->sensorL->getRange(i) << " ";
            }
            cout << "]" << endl;
        }
        else {
            cout << "Access is close." << endl << endl;
        }
        break;
    case 2:
        if (robot->access_control) {
            cout << "<Sonar Datas>" << endl;
            cout << "Sonar ranges are [ ";
            robot->robotinterface->updateSensors();
            for (int i = 0; i < 16; i++) {
                cout << robot->sensorS->getRange(i) << " ";
            }
            cout << "]" << endl;
        }
        else {
            cout << "Access is close." << endl << endl;
        }
        break;
    case 3:
        display();
        break;
    case 4:
        Quit();
        break;
    default:
        cout << "ERROR! Unvalid Entry." << endl << endl;
        break;
    }
    sensor();
};

//function for exit from program.
void Menu::Quit() {
    robot->disconnectRobot(); //disconnect robot before quit from program.
    exit(0);
}
