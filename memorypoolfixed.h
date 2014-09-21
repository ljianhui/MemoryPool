#ifndef _MEMORYPOOLFIXED_H_INCLUDE
#define _MEMORYPOOLFIXED_H_INCLUDE

#include <vector>
#include <cstddef>

class MemoryPoolFixed
{
	public:
		MemoryPoolFixed(size_t unit_size, size_t unit_count);
		MemoryPoolFixed();
		virtual ~MemoryPoolFixed();
		void init(size_t unit_size, size_t unit_count);
		void* alloc();
		bool free(void *unit);

		size_t getFreeUnitCount()const;
		size_t getUsedUnitCount()const;
		bool isFull()const;
	private://function
		MemoryPoolFixed& operator=(const MemoryPoolFixed &pool){}
	private: //data
		size_t _unit_size;
		size_t _unit_count;
		size_t _pool_size;
		void *_pool;
		std::vector<void*> _free_vec;
};

#endif
