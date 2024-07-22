﻿#define	 _USE_MATH_DEFINES
#include<windows.h>
#include<iostream>
using namespace std;


namespace Geometry
{
	enum Color //enum (Enumeration) - это перечисление. Перечисление - набор целочисленных констант.
	{
		RED      = 0x000000FF,
		DARK_RED = 0x00000077,
		GREEN    = 0x0000FF00,
		BLUE     = 0x00FF0000,
		YELLOW   = 0x0000FFFF,

		CONSOLE_BLUE = 0x99,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_DEFAULT = 0x07
	};

#define SHAPE_TAKE_PARAMETERS unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS  start_x, start_y, line_width, color
	class Shape
	{
	protected: 
		//Защищённые поля, доступны только внутри класса, и внутри его дочерних классов. Благодаря protected: к этим полям можно будет обращаться напрямую в дочерних классах без get set методов
		Color color;
		//Координаты, по которым будет выводится фигура:
		unsigned int start_x;
		unsigned int start_y;
		//В любой графической оболочке координаты задаются в пикселях(точка на экране)
		//Начало координат всегда находится в левом верхнем углу.
		unsigned int line_width;  
		//толщина линии, которой будет рисоваться контур фигуры.
	public:
		Shape(SHAPE_TAKE_PARAMETERS) :color(color) 
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		Color get_color()const
		{
			return color;
		}
		void set_color(Color color)
		{
			this->color = color;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			this->line_width = line_width;
		}
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры:" << get_perimeter() << endl;
			draw();//Метод draw() рисует объекты в графическом окне
		}
	};

	/*class Square : public Shape
	{
		double side;
	public:
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		virtual ~Square() {}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, get_color());
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
		}
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			this->side = side;
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << side << endl;
			Shape::info();
		}
	};*/

	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);
		}
		~Rectangle() {}
		double get_area()const override
		{
			return width * height;
		}
		double get_perimeter()const override
		{
			return (width + height) * 2;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow(); 
			//1)Возвращает дискриптор окна консоли. 
			//description - переменная в которой хранится описание чего-то;
			//HWND - Handler to Window (обработчик (Дискриптор) окна)
			HDC hdc = GetDC(hwnd);
			//2) Получаем контекст устройства (Device Context) окна консоли.
			// DC - это то, на чём будем рисовать
			HPEN hPen = CreatePen(PS_SOLID, 5, get_color());
			//3) Создаём карандаш. pen рисует контур фигуры.
			// PS_SOLID - сплошная линия
			// 5 - толщина линии в пикселах
			HBRUSH hBrush = CreateSolidBrush(get_color());

			// 5) Выбираем чем и на чём рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			// 6) Рисуем прямоугольник:
			::Rectangle(hdc, start_x, start_y, /*start_x + width*/800,/*start_y + height*/ 350); 
			//start_x, start_y - координаты верхнего левого угла
			//800,350 - координаты нижнего правого угла.

			//Двойное двоеточие :: без операнда слева означает что класс Rectangle берётся из глобального пространства имён;
			// 7)Освобождаем ресурсы:
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
			/*for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}*/
		}
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		void set_width(double width)
		{
			this->width = width;
		}
		void set_height(double height)
		{
			this->height = height;
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина: " << get_width() << endl;
			cout << "Высота: " << get_height() << endl;
			Shape::info();
		}
	};

	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS){}
		~Square() {}
	};

	class Circle :public Shape
	{
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		double get_diameter()const
		{
			return 2 * radius;
		}
		void set_radius(double radius)
		{
			this->radius = radius;
		}
		Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);
		}
		~Circle() {}
		double get_area()const override
		{
			return M_PI * radius*radius;
		}
		double get_perimeter()const override
		{
			return M_PI * get_diameter();
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	//Square shape(Color::CONSOLE_BLUE);
	Geometry::Square square(5, 300, 50, 5, Geometry:: Color::BLUE);
	/*cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;*/
	square.info();

	Geometry::Rectangle rect(150, 80, 500, 50, 3, Geometry:: Color::BLUE);
	rect.info();

	Geometry::Circle circle(75, 700, 50, 5, Geometry::Color::YELLOW);
	circle.info();
}
