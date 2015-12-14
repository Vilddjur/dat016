#include "keyboardML15.h"
#include "displayML15.h"

void main (void)
{

	while(1){
		char c = get_key();
		display_dec((unsigned int)c);
	}
}









