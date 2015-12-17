#include "drill.h"
#include "ports.h"
#include "clock.h"

static char DCShadow = 0;

static int dataMask[] = {1, 2, 4, 8, 16, 32, 64, 128};


void Outzero(unsigned int bit){
	if(bit <= 7){
		int maskWith = dataMask[bit];
		DCShadow = DCShadow & (~maskWith);
	}
	DRILLCONTROL = DCShadow;
	
}

void Outone(unsigned int bit){
	if(bit <= 7){
		int maskWith = dataMask[bit];
		DCShadow = DCShadow | maskWith;
	}
	DRILLCONTROL = DCShadow;
	
}
void delay(int input){	
	time_type temp = (time_type)input;
	hold(temp);
}
void MotorStart(void){
	Outone(2);
	delay(1000);
	
}


void MotorStop(void)
{
	Outzero(2);
	delay(1000);
}

void DrillDown(void)
{
	Outone(3);
}

void DrillUp(void)
{
	Outzero(3);
}

int Nstep( int input )
{
	return 0;
}
int DrillDownTest(void){
	int amount = 20;
	while(amount){
		if((DRILLSTATUS & 0x04)){//control check if not inverse
			return 1;
		}
		delay(250);
		amount --;
	}
	alarm(2);
	return 0;
}
void Alarm( int amount ){
	while(amount){
		Outone(4);
		delay(500);
		Outzero(4);
		--amount;
		if(amount){
			delay(250);
		}
	}

}
int DrillHole(void){
	int temp = 0;
	DrillDown();
	temp = DrillDownTest();
	DrillUp();
	return temp;
}
int RefPos(void){
	int result = 1;
	while(!(DRILLSTATUS & (0x01))){
		if(!(step())){
			result = 0;
			return result;
		}
	}
	return result;
}
void DoAuto(void){
}

int step(int n){
	int result = 1;
	if (!(DRILLSTATUS & 0x02))
	{
		Alarm(2);
		result = 0;
	} else
	{
		Outone(0);
		Outone(1);
		hold((time_type)500);
		Outzero(1);//do i need this
		Outzero(0);//do i need this
    }	
    return result;
}




