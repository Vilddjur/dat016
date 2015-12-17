#include "drill.h"
#include "ports.h"
#include "clock.h"

static char DCShadow = 0;

static int dataMask[] = {1, 2, 4, 8, 16, 32, 64, 128};
static int borr_auto[] = {0,1,1,1,1,1,1,1,2,1,5,2,2,2,2,4,4,3,8,2,0xFF};

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
//	delay(1000);
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
	int tmp=0;
	while(input){
		input--;
		tmp = step();
		if(!tmp){
			return 0;
		}
	}
	return 1;
}
int DrillDownTest(void){
	int amount = 20;
	while(amount){
		if((DRILLSTATUS & 0x04)){//control check if not inverse
			return 1;
		}
		delay(250);
		amount--;
	}
	alarm(2);
	return 0;
}
void alarm( int amount ){
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
	delay(1000);
	return temp;
}
int RefPos(void){
	int result = 1;
	while(!(DRILLSTATUS & 0x01)){
		if(!(step())){
			result = 0;
			return result;
		}
	}
	return result;
}
void DoAuto(void){
	int tmp = 0;
	int b = 0;
	int i = 0;
	tmp = RefPos();
	if(!tmp){
		MotorStop();
		return;
	}
	MotorStart();
	for(;i<20;i++){
		b = borr_auto[i];
		//if
		tmp = Nstep(b);
		if(!tmp){
			MotorStop();
			return;
		}
		tmp = DrillHole();
		if(!tmp){
			MotorStop();
			return;
		}		
	}
	MotorStop();
	return;
}

int step(){
	int result = 1;
	if (!(DRILLSTATUS & 0x02))
	{
		alarm(3);
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




