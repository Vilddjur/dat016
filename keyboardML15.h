typedef	unsigned char *port8ptr;

#define ML15_ADDR 	0x9C0

#define	ML15IN		*((port8ptr) ML15_ADDR)

char get_key();
