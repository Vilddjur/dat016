typedef unsigned long int time_type;
typedef volatile unsigned char *ptr8;

typedef void (*voidfuncptr)(void);
typedef voidfuncptr *vector;

#define SIMULATOR
#ifdef SIMULATOR
#define irqAddr 0x3FF0
#else
#define irqAddr 0x3FF0
#endif	

#define CRGINT_ADDR 0x0038
#define RTICTL_ADDR 0x003B
#define CRGFLG_ADDR 0x0037

#define CRGINT *((ptr8) CRGINT_ADDR)
#define RTICTL *((ptr8) RTICTL_ADDR)
#define CRGFLG *((ptr8) CRGFLG_ADDR)

#define irqVector *((vector) irqAddr)

void init_clock();
void clock_inter();
time_type get_time();
void hold(time_type);
