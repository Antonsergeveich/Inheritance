#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void sound() = 0; //����� ����������� ����� ��� ��� � ����� " = 0"
};
class Cat:public Animal{};
class Tiger :public Cat //���������� �����, ���������  � Tiger ���������� ��������� ��� ����� ������ ����������� �����;
{
public:
	void sound() override
	{
		cout << "RRRRRRRR" << endl;
	}
};
class HomeCat :public Cat //���������� �����
{
public:
	void sound() override
	{
		cout << "MIAYYYYY" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Hello AbstractBaseClasses" << endl;
	//Animal animal;
	//Cat cat;
	Tiger tiger;
	tiger.sound();
	HomeCat Tom;
	Tom.sound();

}