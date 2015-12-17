typedef	unsigned char *port8ptr;

#define DISP_MODE_ADDR 	0x9C2
#define DISP_DATA_ADDR 	0x9C3

#define	DISP_MODE	*((port8ptr) DISP_MODE_ADDR)
#define DISP_DATA	*((port8ptr) DISP_DATA_ADDR)

void display_digits(unsigned char[]);
void display_dec(unsigned int);
