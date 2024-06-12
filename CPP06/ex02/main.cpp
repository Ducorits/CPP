#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <iostream>
#include <cstdlib>

/*
Dynamic cast can upcast or downcast a class.
Downcasting is a cast that takes a base class and casts
it to a derived class.
Upcasting takes a derived class and casts it to a base class.
The base class needs to be "polymorphic".
A polymorphic class is a class with a virtual function.

Dynamic cast cannot cast to different derived classes of a single base class.
When you try to do this on a pointer of such a class it returns NULL.
When you try it on a reference it throws an error.

Knowing this behaviour we can determine which of the derived classes the pointer or reference belongs to.
*/

Base *generate(void)
{
	int random_number;

	std::srand(time(0));
	random_number = std::rand() % 3;

	if (random_number == 0)
	{
		std::cout << "Generated type A" << std::endl;
		return (new A);
	}
	else if (random_number == 1)
	{
		std::cout << "Generated type B" << std::endl;
		return (new B);
	}
	else if (random_number == 2)
	{
		std::cout << "Generated type C" << std::endl;
		return (new C);
	}
	std::cout << "Generated type A, in the end" << std::endl;
	return (new A);
}

void identify(Base *p)
{
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	c = dynamic_cast<C *>(p);

	if (a != NULL)
		std::cout << "The pointer type is A" << std::endl;
	else if (b != NULL)
		std::cout << "The pointer type is B" << std::endl;
	else if (c != NULL)
		std::cout << "The pointer type is C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A a;
		a = dynamic_cast<A &>(p);
		std::cout << "The reference type is A." << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		B b;
		b = dynamic_cast<B &>(p);
		std::cout << "The reference type is B." << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		C c;
		c = dynamic_cast<C &>(p);
		std::cout << "The reference type is C." << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
}

int main()
{
	Base *whatami;

	whatami = generate();

	identify(whatami);
	identify(*whatami);

	delete whatami;
}
