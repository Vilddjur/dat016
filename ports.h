typedef	unsigned char *port8ptr;

#define ML4OUT_ADDR 	0x400
#define	ML4IN_ADDR	0x600

#define	ML4OUT	*((port8ptr) ML4OUT_ADDR)
#define	ML4IN	*((port8ptr) ML4IN_ADDR)

