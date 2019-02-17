#include"PQ.h"

template<class type> PQ<type>::PQ(int max)
{
maxItems = max;
items.elements = new type[maxItems];
length = 0;
}
template<class type> PQ<type>::~PQ()
{
delete[] items.elements;
}
template<class type> PQ<type>::PQ(const PQ<type>& jobs)
{
this->maxItems = jobs.maxItems;
this->length = jobs.length;
this->items.elements = new type[maxItems];

for (int i = 0; i < length; i++)
{
this->items.elements[i] = jobs.items.elements[i];
}
}
template<class type> void PQ<type>::makeEmpty()
{
length = 0;
}
template<class type> void PQ<type>::Enqueue(type newItem)
{
if (!isFull())
{
length++; // space for new item
items.elements[length - 1] = newItem;
items.ReHeapUp(0, length - 1);
}
}
template<class type> void PQ<type>::Dequeue(type& item)
{
if (!isEmpty())
{
item = items.elements[0];
items.elements[0] = items.elements[length - 1];
length--;
items.ReHeapDown(0, length - 1);
}
}
template<class type> bool PQ<type>::isFull()
{
return length == maxItems;
}
template<class type> bool PQ<type>::isEmpty()
{
return length == 0;
}
template<class type> int PQ<type>::LengthIs()
{
return length;
}