#include "ports.h"

void main(void)
{
	char c;
	while(1){
		c = ML4IN;
		c = c >> 1;
		ML4OUT = c;
	}
}
