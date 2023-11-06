/*
 * dht11_atmega.c
 *
 * Created: 25.10.2023 17:01:15
 * Author : calmeyweb
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include "DHT11SimpleLibrary.h"
#include "SegmentDisplay.h"

int main(void)
{
	segment_display_setup();
	dht11_setup();

	char result[4];
	
	while(1)
	{
		//Type 'F' instead of 'C' to see temperature in Fahrenheit
		prepare_data_to_display(result, 'C');
		
		for(int i = 0; i < 1000; i++)
		{
			write_digits(result);
		}
	}
}

