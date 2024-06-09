#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <iostream>
#include <cstdlib>

Base * generate(void)
{
	int random_number;

	std::srand(time(0));
	random_number = std::rand() % 3;

	if (random_number == 0)
	{
		return (new A);
	}
	else if (random_number == 1)
	{
		return (new B);
	}
	else if (random_number == 2)
	{
		return (new C);
	}
	return (new A);
}

void identify(Base* p)
{
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	c = dynamic_cast<C *>(p);

	if (a != NULL)
		std::cout << "Type is A" << std::endl;
	else if (b != NULL)
		std::cout << "Type is B" << std::endl;
	else if (c != NULL)
		std::cout << "Type is C" << std::endl;
}

void identify(Base& p)
{

}

int	main()
{
	Base * whatami;

	whatami = generate();

	identify(whatami);

	delete whatami;
}
