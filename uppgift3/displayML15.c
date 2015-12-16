#include "displayML15.h"

void display_digits(unsigned char data[]){
	int i = 0;
	DISP_MODE = 1;
	DISP_DATA = 0xD0;
	DISP_MODE = 0;
	for(i=0;i<6;i++){
		DISP_DATA = *data;
		data++;
	}
	DISP_DATA = 0;
	DISP_DATA = 0;
}

void display_dec(unsigned int input){
	int temp = input;
	
	int counter = 0;
	int fillzero = 0;
	int j = 5;
	unsigned char arr[6];
	
	while(temp){
		temp = temp / 10;
		counter = counter + 1;
	}
	while(fillzero < 6 - counter){
		arr[fillzero] = 0;
		fillzero ++;
	}
	while(input){ //fill backwards
		arr[j] = input % 10;
		input /= 10;
		j--;
	}
	display_digits(arr);
}
