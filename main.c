// use MinGW gcc

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <inttypes.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"

int CPORT_NR ;
int BDRATE = 38400;
char mode[]={'8','N','1',0};
char tx_buf[512]= {0,0,0,0,0,0,0,0,0};

void RS232_tx();
void RS232_rx();

uint8_t IsConnected = 0;

int main(void) {
	printf("Available port: ");
	for (CPORT_NR = 0; CPORT_NR < 16; CPORT_NR++) {
		if(!RS232_OpenComport(CPORT_NR, BDRATE, mode)) {
			RS232_CloseComport(CPORT_NR);
			printf("COM%d ", CPORT_NR+1);
		}
	}
	return (0);
}
