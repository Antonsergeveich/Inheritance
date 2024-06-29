#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define delimiter "\n---------------------------\n"

using std::cout;
using std::cin;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS  last_name, first_name, age

class Human
{
	static const int HUMAN_TYPE_WIDTH = 15;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 5;

	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//             Constructors:

	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//               Methods:
	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << " y/o";
	}
	virtual std::ostream& info(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " y/o";
	}
	virtual std::ofstream& info(std::ofstream& ofs)const
	{
		//ofs << strchr(typeid(*this).name(), ' ') + 1 << ":\t" << last_name << " " << first_name << " " << age;
		ofs.width(HUMAN_TYPE_WIDTH); ofs << left << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";
		ofs.width(LAST_NAME_WIDTH);  ofs << left << last_name;
		ofs.width(FIRST_NAME_WIDTH); ofs << left << first_name;
		ofs.width(AGE_WIDTH);        ofs << left << age;
		//Функция width () позволяет задать минимальную ширину поля для вывода значения
		//При вводе она задает максимальное число читаемых символов. 
		//Если выводимое значение имеет меньше символов, чем заданная ширина поля,
		//то оно дополняется символами-заполнителями до заданной ширины (по умолчанию – пробелами). 
		//Однако если выводимое значение имеет больше символов, чем ширина отведенного ему поля,
		//то поле будет расширено до нужного размера.
		return ofs;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.info(ofs);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
	static const int  SPECIALITY_WIDTH = 25;
	static const int  GROUP_WIDTH = 8;
	static const int  RATING_WIDTH = 8;
	static const int  ATTENDANCE_WIDTH = 8;
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//                  Constructtors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//              Methods:
	void info()const override //переопределить
	{
		Human::info();
		cout << speciality << " " << group << " " << rating << " " << attendance;
	}
	std::ostream& info(std::ostream& os)const override //переопределить
	{
		return Human::info(os) << " "
			<< speciality << " " << group << " " << rating << " " << attendance;
	}
	std::ofstream& info(std::ofstream& ofs)const override
	{
		Human::info(ofs);
		ofs.width(SPECIALITY_WIDTH); ofs << speciality;
		ofs.width(GROUP_WIDTH);      ofs << group;
		ofs.width(RATING_WIDTH);     ofs << rating;
		ofs.width(ATTENDANCE_WIDTH); ofs << attendance;
		return ofs;
	}
};

class Teacher : public Human
{
	static const int SPECIALITY_WIDTH = 25;
	static const int EXPERIENCE_WIDTH = 5;
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//                    Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, const std::string& speciality, unsigned int experience) :
		Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//                       Methods:
	void info()const
	{
		Human::info();
		cout << speciality << " " << experience << " years";
	}
	std::ostream& info(std::ostream& os)const
	{
		return Human::info(os) << " " << speciality << " " << experience << " years";
	}
	std::ofstream& info(std::ofstream& ofs)const override
	{
		Human::info(ofs);
		ofs.width(SPECIALITY_WIDTH);ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH);ofs << experience;
		return ofs;
	}
};

class Graduate : public Student
{
	static const int SUBJECT_WIDTH = 32;
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//                 Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject) :
		Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//     Methods:
	void info()const override
	{
		Student::info();
		cout << subject << endl;
	}
	std::ostream& info(std::ostream& os)const override
	{
		return Student::info(os) << " " << subject;
	}
	std::ofstream& info(std::ofstream& ofs)const override
	{
		Student::info(ofs);
		ofs.width(SUBJECT_WIDTH); ofs << subject;
		return ofs;
	}
};

void Print(Human* group[], const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->info();
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}
}
void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
}
void Save(Human* group[], const int n, const std::string& falename)
//функция которая записывает в файл; falename - файл в который будем сохранять массив;
{
	std::ofstream fout(falename);//создаём поток
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl; //Записываем в файл содержимое массива group;
	}
	fout.close(); //закрываем поток;
	std::string cmd = "notepad " + falename;
	system(cmd.c_str());  // для того чтобы объект класса string преобразовать в строку
	// вызываем метод c_str(), который возвращает содержимое объекта std::string ввиде обычной C-string (NULL Terminated line)
}

//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Vercetty", "Tommy", 30);
	human.info();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97);
	student.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();
#endif // INHERITANCE_CHECK

	/*
	Polymorphism (Poly - много, Morphis - форма) Многоформенность
	--------------------
	AdHoc Polymorphism - Static polymorphism (поскольку отрабатывает на этапе компиляции),
	это способность объектов вести себя по разному в зависимости от обстоятельств;
	Реализуется перегрузкой функций и в частности перегрузкой операторов;
	--------------------
	Inclusion Polymorphism - Полиморфизм подтипов;
	это способность объектов  вести себя по разному, в зависимости от того, кем они являются;
	Realization:

	1. Base Class Pointer - Generalization (Обобщение) Указатели на базовый класс;
	The address of the child object can be saved in the pointer to the base class
	(в указатель на базовый класс можно сохранить адрес дочернего объекта);
	Upcast (приведение к базовому типу);
	2. Virtual functions - Specialization (уточнение) единственная возможнасть заглянуть из базового класса в дочерний;
	DownCast
	Виртуальным метод - это метод который может быть переопределён
	в дочернем классе с учётом его полей;
		VFPTR - Virtual Functions Pointers (Таблица указателей на виртуальные функции)
		При переопределении виртуальной функции в дочернем классе
		её обязательно нужно обозначить ключевым словом
		OVERRIDE;
	*/
	//    Generalization
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder","Hank",40,"Criminalisttic","OBN", 80,90, "How to catch Heisenberg"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98),
		new Teacher("Diaz","Ricardo", 50, "Weapons distribution", 20)
	};
	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	Clear(group, sizeof(group) / sizeof(group[0]));
}