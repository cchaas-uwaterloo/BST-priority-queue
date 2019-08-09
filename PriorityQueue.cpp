#include <cstring>
#include <iostream>
#include <math.h>
#include <cstddef>
#include "PriorityQueue.hpp"
using namespace std;

typedef PriorityQueue::DataType DataType;

PriorityQueue::PriorityQueue(unsigned int capacity)
{
	heap_ = new DataType[capacity+1];
	capacity_ = capacity;
	size_ = 0;
}

PriorityQueue::~PriorityQueue()
{
	delete [] heap_;
	heap_ = nullptr;
}

bool PriorityQueue::full() const
{
	if (size_ >= capacity_)
		return true;
	return false;
}

bool PriorityQueue::empty() const
{
	if (size_ == 0)
		return true;
	return false;
}

bool PriorityQueue::enqueue(DataType val)
{
	if (full())
		return false;

	heap_[size_+1] = val;
	size_++;
	unsigned int currentPos = size_;
	while (heap_[currentPos]>heap_[currentPos/2])
	{
		unsigned int temp = heap_[currentPos/2];
		heap_[currentPos/2] = heap_[currentPos];
		heap_[currentPos] = temp;
		currentPos = currentPos/2;
	}

	return true;
}

bool PriorityQueue::dequeue()
{
	if (empty())
		return false;

	heap_[1] = heap_[size_];
	unsigned int currentPos = 1;
	size_--;
	while ((currentPos*2 < size_)&&heap_[currentPos]<std::max(heap_[currentPos*2],heap_[currentPos*2+1]))
	{
		unsigned int temp;
		if (heap_[currentPos*2]>heap_[currentPos*2+1])
		{
			temp = heap_[currentPos*2];
			heap_[currentPos*2] = heap_[currentPos];
			heap_[currentPos] = temp;
		}
		else
		{
			temp = heap_[currentPos*2+1];
			heap_[currentPos*2+1] = heap_[currentPos];
			heap_[currentPos] = temp;
		}
	}

	return true;
}

DataType PriorityQueue::max() const
{
	if (empty())
		return -1;
	return heap_[1];
}

unsigned int PriorityQueue::size() const
{
	return size_;
}

void PriorityQueue::print() const
{
	for (unsigned int i = 0; i<size_; i++)
		cout << " " << heap_[i+1];
	cout << endl;
	return;
}
