#include "clock.h"
extern void reset_i(void);
extern void irq_rut(void);

time_type clock;

void init_clock()
{
	clock = 0;
	irqVector = irq_rut;
	RTICTL = 0x0049;
	CRGINT |= 0x80;
	reset_i();
	CRGFLG |= 0x80;
	
}

void clock_inter()
{	
	clock++;
	CRGFLG |= 0x80;
//kvittera rtif
}
time_type get_time()
{
	return clock*10;
}
void hold(time_type);
