#pragma once
#ifndef MUTANT_STACK
#define MUTANT_STACK

template <typename T>
class MutantStack {
	public:
	const MutantStack<T>& top() const;
	bool empty();
	size_t size();
	void push();
	void pop();


	private:

}




#endif // MUTANT_STACK