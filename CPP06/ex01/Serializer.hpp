#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


struct Data
{
	int numnum;
	char charactarrrr;
	double doubly_numbly;
};

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		virtual ~Serializer();
		// Copy constructor
		Serializer(const Serializer &obj);
		// Operator overload
		Serializer &operator=(const Serializer &obj);
}

#endif // SERIALIZER_HPP