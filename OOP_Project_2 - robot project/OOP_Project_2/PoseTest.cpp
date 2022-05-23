/**
 * @file PoseTest.cpp
 * @Author Ozge KATIRCI (ozgekatirci0@gmail.com), Melisa DEMIRHAN (melisa.dmrhn2202@gmail.com)
 * @date January, 2021
 * @brief Test source file of class that take poses and compare them.
 */
#include"Pose.h"


///Main function to create pose objects and use function of pose class.
int main()
{
	Pose p1;
	Pose p2;

	p1.setPose(3.2, 6.8, 40);
	p2.setPose(7.5, 5.4, 25);

	cout << "p1:" << endl << "------------------------------" << endl;
	cout << "x: " << p1.getX() << endl;
	cout << "y: " << p1.getY() << endl;
	cout << "teta: " << p1.getTh() << endl;
	cout << "------------------------------" << endl << endl;
	cout << "p2:" << endl << "------------------------------" << endl;
	cout << "x: " << p2.getX() << endl;
	cout << "y: " << p2.getY() << endl;
	cout << "teta: " << p2.getTh() << endl;
	cout << "------------------------------" << endl << endl;

	Pose p3;
	p3 = p1 + p2;
	cout << "p1+p2" << endl << "------------" << endl;
	cout << "x: " << p3.getX() << endl;
	cout << "y: " << p3.getY() << endl;
	cout << "teta: " << p3.getTh() << endl << endl;

	p1 += p2;
	cout << "p1+=p2" << endl << "------------" << endl;
	cout << "x: " << p1.getX() << endl;
	cout << "y: " << p1.getY() << endl;
	cout << "teta: " << p1.getTh() << endl << endl;

	p3.setX(2.3);
	p3.setY(5.8);
	p3.setTh(62.1);
	Pose p4;
	p4.setX(5.6);
	p4.setY(9.4);
	p4.setTh(92.7);

	cout << "p3:" << endl << "------------------------------" << endl;
	cout << "x: " << p3.getX() << endl;
	cout << "y: " << p3.getY() << endl;
	cout << "teta: " << p3.getTh() << endl;
	cout << "------------------------------" << endl << endl;
	cout << "p4:" << endl << "------------------------------" << endl;
	cout << "x: " << p4.getX() << endl;
	cout << "y: " << p4.getY() << endl;
	cout << "teta: " << p4.getTh() << endl;
	cout << "------------------------------" << endl << endl;

	Pose p5;
	p5 = p4 - p3;
	cout << "p4-p3" << endl << "------------" << endl;
	cout << "x: " << p5.getX() << endl;
	cout << "y: " << p5.getY() << endl;
	cout << "teta: " << p5.getTh() << endl << endl;

	p3 -= p4;
	cout << "p3 -= p4" << endl << "------------" << endl;
	cout << "x: " << p3.getX() << endl;
	cout << "y: " << p3.getY() << endl;
	cout << "teta: " << p3.getTh() << endl << endl;

	p3.setPose(2.3, 5.8, 62.1);
	p4.setPose(5.6, 9.4, 92.7);

	cout << "Distance from p3 to p4: " << p3.findDistanceTo(p4) << endl;
	cout << "Angle between p3 and p4: " << p3.findAngleTo(p4) << " degree" << endl << endl;

	cout << "------------------------------------" << endl;

	if (p3 == p4)
	{
		cout << "p3 and p4 are the same!" << endl;
	}
	else
	{
		cout << "p3 and p4 aren't same!" << endl;
	}

	cout << "------------------------------------" << endl;

	if (p3 < p4)
		cout << "p4 is greater than p3. " << endl;
	else
		cout << "p3 is greater than p4. " << endl;

	cout << "------------------------------------" << endl;
	Pose p6, p7;
	p6.setPose(2.3, 5.8, 62.1);
	p7.setPose(2.3, 5.8, 62.1);
	if (p6 == p7)
	{
		cout << "p6 and p7 are the same!" << endl;
	}
	else
	{
		cout << "p6 and p7 aren't same!" << endl;
	}
	cout << "------------------------------------" << endl;
	return 0;
}