#include "keyboardML15.h"

char get_key(){
	char c = ML15IN;
	short dav = (short)c & 0x80;
	while(dav){
		c = ML15IN;
		dav = (short)c & 0x80;
	}
	return c;
}


