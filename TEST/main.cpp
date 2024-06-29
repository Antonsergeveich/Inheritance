#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");
	std::ofstream fout;
	fout.open("Vasiliy.txt", std::ios_base::app);
	fout << "Where is the Alice robot?!" << endl;
	//time_t now = time(nullptr);
	//fout << ctime(&now) << endl;
	fout.close();
	system("notepad Vasiliy.txt");
}