#include <string>
#include <iostream>

#include <boost/noncopyable.hpp>

//
// copyable class
//
class Person {
public:
	Person(const int &id = 0, const std::string &name = "") : id_(id), name_(name) 
	{
	}

	// copy constrctor
	Person(const Person &obj)
	{
		copy(obj, *this);
	}

	// operator=
	Person& operator=(const Person &obj) 
	{
		copy(obj, *this);
		return *this;
	}

	static void copy(const Person &src, Person &dst) 
	{
		dst.id_   = src.id_;
		dst.name_ = src.name_;
	}

	virtual ~Person() 
	{
	}

	int id() const 
	{
		return id_;
	}

	std::string name() const 
	{
		return name_;
	}

protected:
	int id_;
	std::string name_;
};

//
// noncopyable class - case 1
//
class NonCopyableClass1 {
public:
	NonCopyableClass1() {}

private:
	NonCopyableClass1(const NonCopyableClass1 &obj) {}
	NonCopyableClass1& operator=(const NonCopyableClass1 &obj) { return *this; }
};

//
// noncopyable class - case 2
//
class NonCopyableClass2 : boost::noncopyable {
public:
	NonCopyableClass2() {}
};

std::ostream& operator<<(std::ostream& os, const Person &p)
{
	os << "Person{id=" << p.id() << ", name=\"" << p.name() << "\"}";
	return os;
}

int main(int argc, char* argv[])
{
	//
	// copyable class
	//
	Person a(1234, "foobar");
	Person b(a); // copy constructor
	Person c;
	
	c = a; // operator=

	std::cout << b << std::endl;
	std::cout << c << std::endl;

	//
	// noncopyable class - case 1
	//
	NonCopyableClass1 ncc1_a, ncc1_b;
	//ncc1_b = ncc1_a;                   // compile error...
	//NonCopyableClass1 ncc1_c(ncc1_a);  // compile error....

	//
	// noncopyable class - case 2
	//
	NonCopyableClass2 ncc2_a, ncc2_b;
	//ncc2_b = ncc2_a;                   // compile error...
	//NonCopyableClass2 ncc2_c(ncc2_a);  // compile error....

	return 0;
}