#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<ctime> //time.h

using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define WRITE_TO_FILE
#define READ_TO_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	std::ofstream fout;           //1) ������ �����:
	fout.open("File.txt", std::ios_base::app);        //2) ��������� �����:�
	// std::ios_base::app - append (�������� ����� �����) ������� ��� ������ ����, ������� ��� ��������� HelloWorld;
	fout << "HelloWorld" << endl; //3) ����� � �����.
	time_t now = time(NULL);
	fout << ctime(&now) << endl;

	fout.close();                 //4) ��������� �����.
	// ���� ������ "fout.open()", ��  ����������� !!! ������ "fout.close()", ��� �����������;
	// Solution Explorer -> ������ ������� �� ������ -> Open Folder in File Explorer; 

	system("notepad File.txt"); // ��������� ���� �����  
#endif // WRITE_TO_FILE

#ifdef READ_TO_FILE
	//1)������ � ��������� �����:
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//����� ����� ������ ����:
		const int SIZE = 256; //������ ������
		char buffer[SIZE]{};  //�����

		while (!fin.eof())    //NOT EndOfFile
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);  //������ ������ � ���������
			cout << buffer << endl;
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

#endif // READ_TO_FILE
}