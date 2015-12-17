typedef	unsigned char *port8ptr;

//#define ML4OUT_ADDR 	0x400
//#define	ML4IN_ADDR	0x600

#define	ML4OUT	*((port8ptr) ML4OUT_ADDR)
#define	ML4IN	*((port8ptr) ML4IN_ADDR)
//#ifdef  SIMULATOR
//	#define DRILLSTATUS_ADDRESS 0x401
//#else
	#define DRILLSTATUS_ADDRESS 0x600
//#endif
#define DRILLCONTROL_ADDRESS        0x400
 
#define DRILLSTATUS *((port8ptr)DRILLSTATUS_ADDRESS)
#define DRILLCONTROL    *((port8ptr)DRILLCONTROL_ADDRESS)
