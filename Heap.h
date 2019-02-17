#ifndef HEAP_DEFINED
#define HEAP_DEFINED

template<class type>
struct Heap
{
	type * elements;

	void Swap(type&,type&);
	void ReHeapDown(int,int);
	void ReHeapUp(int, int);
};

#include"Heap.cpp"
#endif
