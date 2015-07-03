#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include "memorypoolfixed.h"

using std::cout;
using std::endl;

double CurrentTime()
{
	struct timeval timeVal;
	struct timezone timeZone;
	gettimeofday(&timeVal, &timeZone);
	double curTime  = (double)timeVal.tv_sec + 
		(double)timeVal.tv_usec / (double)1e6;
	return curTime;
}

typedef double DataType;

int main()
{
	double time = 0;
	{
	MemoryPoolFixed pool(sizeof(DataType), 100*1024*1024);
	time = CurrentTime();
	for (int i = 0; i < 100 * 1024 * 1024; ++i)
	{
		DataType *p = (DataType*)pool.alloc();
		*p = i;
		pool.free(p);
	}
	cout << CurrentTime() - time << endl;
	}

	time = CurrentTime();
	for (int i = 0; i < 100 * 1024 * 1024; ++i)
	{
		DataType *p = new DataType;
		*p = i;
		delete p;
	}
	cout << CurrentTime() - time << endl;

	time = CurrentTime();
	for (int i = 0; i < 100 * 1024 * 1024; ++i)
	{
		DataType *p = (DataType*)malloc(sizeof(DataType));
		*p = i;
		free(p);
	}
	cout << CurrentTime() - time << endl;
	return 0;
}

