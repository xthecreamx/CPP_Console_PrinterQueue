#ifndef PQ_DEFINED
#define PQ_DEFINED

#include"Heap.h"

template<class type>
class PQ
{
public:
	PQ(int);
	~PQ();
	PQ(const PQ<type>&);
	void makeEmpty();
	void Enqueue(type);
	void Dequeue(type&);
	bool isEmpty();
	bool isFull();
	int LengthIs();
private:
	int length, maxItems;
	Heap<type> items;
};
#include "PQ.cpp"
#endif
