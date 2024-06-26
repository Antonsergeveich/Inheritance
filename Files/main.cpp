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
	std::ofstream fout;           //1) —оздаЄм поток:
	fout.open("File.txt", std::ios_base::app);        //2) ќткрываем поток:м
	// std::ios_base::app - append (дописать конец файла) сколько раз открыл файл, столько раз дозаписал HelloWorld;
	fout << "HelloWorld" << endl; //3) ѕишем в поток.
	time_t now = time(NULL);
	fout << ctime(&now) << endl;

	fout.close();                 //4) «акрываем поток.
	// ≈сли открыл "fout.open()", то  ќЅя«ј“≈Ћ№Ќќ !!! закрой "fout.close()", как холодильник;
	// Solution Explorer -> правой кнопкой на проект -> Open Folder in File Explorer; 

	system("notepad File.txt"); // открывает окно файла  
#endif // WRITE_TO_FILE

#ifdef READ_TO_FILE
	//1)—оздаЄм и открываем поток:
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//«десь будем читать файл:
		const int SIZE = 256; //размер буфера
		char buffer[SIZE]{};  //буфер

		while (!fin.eof())    //NOT EndOfFile
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);  //„итает строку с пробелами
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