﻿#include<iostream>
#include<string>
using namespace std;

#define delimiter "\n---------------------------\n"

using std::cout;
using std::cin;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS  last_name, first_name, age

class Human
{
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
		cout << last_name << " " << first_name << " " << age << " y/o" << endl;
	}

};

//dynamic_cast<>()
std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " y/o";
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
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
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Student& obj) //переопределить
{
	return os << (Human)obj << " "
		<< obj.get_speciality() << " " << obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendance();
}

class Teacher : public Human
{
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
		cout << speciality << " " << experience << " years" << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	return os << (Human)obj << " " << obj.get_speciality() << " " << obj.get_experience() << " y/o";
}

class Graduate : public Student
{
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
};

std::ostream& operator<<(std::ostream& os, const Graduate& obj)
{
	return os << (Student&)obj << " " << obj.get_subject();
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
	Plymorphism (Poly - много, Morphis - форма) Многоформенность
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
	2. Virtual functions;(единственная возможнасть заглянуть из базового класса в дочерний);
	Виртуальным метод - это метод который может быть переопределён
	в дочернем классе с учётом его полей;
		VFPTR - Virtual Functions Pointers (Таблица указателей на виртуальные функции)
		При переопределении виртуальной функции в дочернем классе
		её обязательно нужно обозначить ключевым словом
		OVERRIDE;
	*/
	//    Generalization (UpCast) обобщение:
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder","Hank",40,"Criminalisttic","OBN", 80,90, "How to catch Heisenberg"),
		new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98)
	};

	cout << delimiter << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//group[i]->info();
		cout << typeid(*group[i]).name() << ":\t";
		//https://legacy.cplusplus.com/doc/tutorial/typecasting/
		//Specialization (DownCast) - уточнение:
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		cout << delimiter << endl;
		//member-function
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}