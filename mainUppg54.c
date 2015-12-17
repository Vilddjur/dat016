#include "drill.h"
#include "clock.h"

int main(void){
	int key=0;
	init_clock();
	while(1){
		key = get_key();
		switch(key){
			case 0:
				MotorStart();
			break;
			case 1:
				MotorStop();
			break;
			case 2:
				DrillDown();
			break;
			case 3:
				DrillUp();
			break;			
			case 4:
				step();
			break;
			case 5:
				DrillHole();
			break;
			case 6:
				RefPos();
			break;
			case 7:
				DoAuto();
			break;
		}
	}
	return 0;
}