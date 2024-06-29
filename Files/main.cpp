﻿#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<ctime> //time.h

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define WRITE_TO_FILE
//#define READ_TO_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	std::ofstream fout;                               //1) Создаём поток:
	fout.open("File.txt", std::ios_base::app);        //2) Открываем поток:
	// std::ios_base::app - append (дописать конец файла) сколько раз открыл файл, столько раз дозаписал HelloWorld;
	fout <<"Привет сам" << endl; //3) Пишем в поток.
	time_t now = time(NULL); //
	//Временной(ударение на 'о') тип данных time_t способен представлять дату и время
	//и поддерживает арифметические операции. 
	//Этот тип данных используется в качестве возвращаемого значения функции time() 
	//и используется в качестве параметра в некоторых других функциях заголовочного файла <ctime>;
	//Этот тип данных используется для представления целого числа — количества секунд,
	//прошедших после полуночи 00:00, 1 января 1970 года в формате GMT.
	//GMT расшифровывается как Greenwich Mean Time (среднее время по Гринвичу)
	//то есть это время на часах Королевской обсерватории в Гринвиче,Великобритания.
	//Она расположена на нулевом меридиане. 
	//Радиосигнал GMT-системы начал транслироваться с 5 февраля 1924 года, 
	//а сама она превратилась в мировой стандарт с 1 января 1972 года.
	//К примеру, часовой пояс Москвы Europe/Moscow GMT+3.
	
	fout << ctime(&now) << endl; //Вывод даты и времени в файл при открытии файла
	//Функция ctime в C++ преобразует значение типа time_t в строку,
	//которая содержит дату и время в человекопонятном формате.
	//Возвращаемая строка имеет следующий формат:
	//1)это день недели; 2)месяц; 3)день; 4)чч: мм: сс — время; 5)гггг — год.
	fout.close();                 //4) Закрываем поток.
	// Если открыл "fout.open()", то  ОБЯЗАТЕЛЬНО !!! закрой "fout.close()", как холодильник;
	// Solution Explorer -> правой кнопкой на проект -> Open Folder in File Explorer; 

	system("notepad File.txt"); // открывает окно файла (чтобы каждый раз не заходить в папку и открывать файл)
	//открывается файлик с консолью;

#endif // WRITE_TO_FILE

#ifdef READ_TO_FILE
	//1)Создаём и открываем поток:
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//Здесь будем читать файл:
		const int SIZE = 256; //размер буфера
		char buffer[SIZE]{};  //буфер

		while (!fin.eof())    //NOT EndOfFile
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);  //Читает строку с пробелами
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