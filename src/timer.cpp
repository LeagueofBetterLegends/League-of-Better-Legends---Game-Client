//timer.cpp

#include "timer.h"
#include <sys/time.h>
#include <stdlib.h>

timer::timer()
{
	reset();

}

int getmstime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec*1000)+(tv.tv_usec/1000);


}

void timer::reset()
{
	m_start = getmstime();

}

int timer::elapsed()
{
	return getmstime() -  m_start;

}

int timer::elapsed_seconds()
{
	return elapsed()/1000;

}
