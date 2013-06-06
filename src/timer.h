//timer.h
#ifndef TIMER_H
#define TIMER_H

class timer
{
public:
	timer();
	void reset();
	int elapsed();
	int elapsed_seconds();

private:
	int m_start;

};

#endif /*TIMER_H*/
