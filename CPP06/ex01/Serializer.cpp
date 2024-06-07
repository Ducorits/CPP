#include <Serializer.hpp>
/*
After reading up on the subject, I have concluded that for this exercise we need reinterpret_cast.
Though in the new c++20 standard we would use bit_cast. Bit cast is the standards compliant way for bit preserving type conversion.
*/

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	return *this;
}

Serializer::Serializer(const Serializer &obj)
{
	*this = obj;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw_ptr)
{
	return (reinterpret_cast<Data *>(raw_ptr));
}