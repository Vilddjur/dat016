#include "clock.h"
#include "displayML15.h"

extern void reset_i(void);
extern void irq_rut(void);

static time_type clock;
void init_clock()
{
	clock = 0;
	irqVector = irq_rut;
	//#ifdef SIMULATOR
	//RTICTL = 0x10;
	//#else
	RTICTL = 0x49;
	//#endif
	CRGINT |= 0x80;
	reset_i();
	//CRGFLG |= 0x80;
	
}

void clock_inter()
{	//display_dec((int)clock);
	clock++;
	CRGFLG = 0x80;
//kvittera rtif
}
time_type get_time()
{
	return clock*10;
}
void hold(time_type input){

	time_type start_time = get_time();
	while((get_time() - start_time) < input);
	//while(get_time() != start_time);
}
