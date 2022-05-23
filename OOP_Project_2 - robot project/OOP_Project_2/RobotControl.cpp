/**
 * @file RobotControl.cpp
 * @Author Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Source file of class that controlling the robot's moves.
 */
#include <iostream>
#include "PioneerRobotAPI.h"
#include "Pose.h"
#include"RobotControl.h"
#include "Record.h"


using namespace std;
RobotControl::RobotControl(RobotInterface* robot, RangeSensor* sens, RangeSensor* sens1, Pose* pose)
{
	access_control = false;
	admin = new RobotOperator(1234);
	p = new Path;
	sensorS = sens;
	sensorL = sens1;
	robotinterface = robot;
	robotinterface->setPose(pose);
	robotinterface->updaterobot();
	robotinterface->setSensors(sens, sens1);
	robotinterface->updateSensors();
}

RobotControl::~RobotControl() {
	delete position, p, admin, sensorS, sensorL;
}
void RobotControl::updatePose() {
	if (access_control) { robotinterface->updaterobot(); }
	else { cout << "Access is close." << endl; }

}
bool RobotControl::connectRobot() {
	if (access_control) { return robotinterface->connectRobot(); }
	else { cout << "Access is close." << endl; }
}
void RobotControl::disconnectRobot() {
	if (access_control) { robotinterface->disconnectRobot(); }
	else { cout << "Access is close." << endl; }
}
//turning robot to left.
void RobotControl::turnLeft() {
	if (access_control) { robotinterface->turnLeft(); }
	else { cout << "Access is close." << endl; }
}
//turning robot to right.
void RobotControl::turnRight() {
	if (access_control) { robotinterface->turnRight(); }
	else { cout << "Access is close." << endl; }
};
//moving robot forward.
void RobotControl::forward_(float speed) {
	if (access_control) { robotinterface->forward_(speed); }
	else { cout << "Access is close." << endl; }
}
//print position's datas.
void RobotControl::print() {
	if (access_control) { robotinterface->print(); }
	else { cout << "Access is close." << endl; }

}
//moving robot backward.
void RobotControl::backward(float speed) {
	if (access_control) { robotinterface->backward(speed); }
	else { cout << "Access is close." << endl; }
}
Pose RobotControl::getPose() {
	if (access_control) { return robotinterface->getPose(); }
	else { cout << "Access is close." << endl; }

}
void RobotControl::setPose(Pose* position) {
	if (access_control) { robotinterface->setPose(position); }
	else { cout << "Access is close." << endl; }
}
//stop robot's turning.
void RobotControl::stopTurn() {
	if (access_control) { robotinterface->stopTurn(); }
	else { cout << "Access is close." << endl; }
}
//stop robot's move.
void RobotControl::stopMove() {
	if (access_control) { robotinterface->stopMove(); }
	else { cout << "Access is close." << endl; }
}
// o addToPath() fonksiyonu, robotun bulunduðu konum(pose) path’e eklenmektedir.
//(Path nesnesi kullanýlarak)
bool RobotControl::addToPath() {
	if (access_control) {
		p->addPos(getPose());
		if (getPose() == p->getPos(p->number)) {

			return true;
		}
		else {
			return false;
		}
	}
	else { cout << "Access is close." << endl; }
}
//o clearPath() fonksiyonu ile, path temizlenmektedir.Yani eklenen tüm konumlar
//silinmektedir(Path nesnesi kullanýlarak)
bool RobotControl::clearPath() {
	if (access_control) {
		Node* temp = new Node();
		while (p->head != NULL) {
			temp = p->head;
			p->head = p->head->next;
			free(temp);
		}
		if (!p->head) {
			return true;
		}
		else { return false; }
	}
	else { cout << "Access is close." << endl; }
}
//o recordPath() fonksiyonu ile, Path nesnesinde yüklenmiþ olan konumlar dosyaya
//yazdýrýlmaktadýr. (Path ve Record nesneleri kullanýlarak)
bool RobotControl::recordPath() {

	if (access_control) {
		Record r;
		r.setFileName("pathinput.txt", "pathoutput.txt");

		if (!r.open_output_File()) {
			cout << "ERROR!Output file is couldn't open." << endl;
			return false;
		}
		else {
			Node* a = p->head;
			while (a != NULL) {
				r.writeLine(to_string(a->pose.getX()));
				r.writeLine(" ");
				r.writeLine(to_string(a->pose.getY()));
				r.writeLine(" ");
				r.writeLine(to_string(a->pose.getTh()));
				r.writeLine("\n");
				a = a->next;
			}
			return true;
		}
	}
	else { cout << "Access is close." << endl; }
}
//    o closeAccess() fonksiyonu ile doðru þifre verildiðinde, eriþim tekrar kapatýlacaktýr.
//    Tekrar açýlana kadar fonksiyonlar iþlemlerini yapmayacaktý
bool RobotControl::closeAccess(int accessCode) {
	if (!access_control) {
		if (admin->checkAccessCode(accessCode)) {
			return true;
			access_control = false;
		}
		else {
			return false;
		}
	}
	else { cout << "Access is already close." << endl; }
}
//o openAccess() fonksiyonu, eriþim için kullanýlmaktadýr.Bu fonksiyon üzerinden, doðru
//þifre giriþ yapýlmadýðý takdirde, RobotControl sýnýfýnýn hiçbir fonksiyonu bir iþlem
//yapmayacaktýr.Tüm fonksiyonlar çaðrýldýðýnda iþlem yapmadan dönecektir.Bu fonksiyon
//kullanýlarak doðru þifre verildi ise, tüm üye fonksiyonlar yapmasý gereken iþlemi
//yapacaktýr. (RobotControl sýnýfý altýna bir boolean deðiþken tanýmlayýp, þifrenin
//    girilip / girilmediðine göre true / false yapýlýp, tüm fonksiyonlarýn bu deðiþkeni kontrol
//    etmesi saðlanabilir.)
bool RobotControl::openAccess(int accessCode) {
	if (access_control) { cout << "Access already open." << endl; }
	else {
		if (admin->checkAccessCode(accessCode)) {
			return true;
			access_control = true;
		}
		else {
			return false;
		}
	}

}