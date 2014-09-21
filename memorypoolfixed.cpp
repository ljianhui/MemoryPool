#include <memory.h>
#include "memorypoolfixed.h"

MemoryPoolFixed::MemoryPoolFixed(size_t unit_size, size_t unit_count):
	_free_vec(unit_count, NULL)
{
	init(unit_size, unit_count);
}

MemoryPoolFixed::MemoryPoolFixed():
	_unit_size(0),
	_unit_count(0),
	_pool_size(0),
	_pool(NULL)
{
}

MemoryPoolFixed::~MemoryPoolFixed()
{
	if(_pool != NULL)
	{
		delete[] (char*)_pool;
	}
}

void MemoryPoolFixed::init(size_t unit_size, size_t unit_count)
{
	if(_free_vec.capacity() != unit_count)
	{
		_free_vec.clear();
		_free_vec.reserve(unit_count);
	}
	_unit_size = unit_size;
	_unit_count = unit_count;
	_pool_size = unit_size * unit_count;

	char *pool = new char[_pool_size];
	_pool = (void*)pool;
	for(std::vector<void*>::iterator it = _free_vec.begin();
	    it != _free_vec.end(); ++it)
	{
		*it = (void*)pool;
		pool += unit_size;
	}
}

void* MemoryPoolFixed::alloc()
{
	if(_free_vec.empty())
	{
		return NULL;
	}
	void *unit = _free_vec.back();
	bzero(unit, _unit_size);
	_free_vec.pop_back();
	return unit;
}

bool MemoryPoolFixed::free(void *unit)
{
	char *pool_end = (char*)_pool + _pool_size - 1;
	if(unit < _pool || unit > (void*)pool_end)
	{
		return false;
	}

	_free_vec.push_back(unit);
	return true;
}

size_t MemoryPoolFixed::getFreeUnitCount()const
{
	return _free_vec.size();
}

size_t MemoryPoolFixed::getUsedUnitCount()const
{
	return _unit_count - _free_vec.size();
}

bool MemoryPoolFixed::isFull()const
{
	return _free_vec.empty();
}

