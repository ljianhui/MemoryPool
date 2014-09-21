#include <stdio.h>
#include "memorypoolfixed.h"

int main()
{
	MemoryPoolFixed pool(sizeof(int), 100);
	int *p1 = (int*)pool.alloc();
	*p1 = 1;
	int *p2 = (int*)pool.alloc();
	*p2 = 2;
	int *p3 = (int*)pool.alloc();
	*p3 = 3;
	printf("%d, %d, %d\n", *p1, *p2, *p3);
	printf("used: %lu, free: %lu\n", pool.getUsedUnitCount(), pool.getFreeUnitCount());
	pool.free(p2);
	printf("used: %lu, free: %lu\n", pool.getUsedUnitCount(), pool.getFreeUnitCount());
	return 0;
}
