/*
 * DHT11SimpleLibrary.c
 *
 * Created: 04.11.2023 13:56:37
 *  Author: calmeyweb
 */ 

#include "DHT11SimpleLibrary.h"

unsigned char dht11_data[] = {0, 0, 0, 0, 0};

void dht11_setup()
{
	_delay_ms(1500);
}

int dht11_read_data()
{
	dht11_data[0] = 0;
	dht11_data[1] = 0;
	dht11_data[2] = 0;
	dht11_data[3] = 0;
	dht11_data[4] = 0;
	DHT11_DDR |= (1<<DHT11);
	_delay_ms(20);
	DHT11_DDR &= ~(1<<DHT11);
	
	_delay_us(60);
	if(DHT11_PIN & (1<<DHT11)) return 1;
	_delay_us(80);
	if(!(DHT11_PIN & (1<<DHT11))) return 2;
	while(DHT11_PIN & (1<<DHT11));
	
	for(int i = 0; i<5; i++)
	{
		uint8_t j = 8;
		while(j--) {
			while(!(DHT11_PIN & (1<<DHT11)));
			_delay_us(40);
			if(DHT11_PIN & (1<<DHT11))
			{
				dht11_data[i] |= (1<<j);
				while(DHT11_PIN & (1<<DHT11));
			}
		}
	}
	return 0;
}

int dht11_get_data(char data)
{
	switch(data)
	{
		case 'H':
		return dht11_data[0];
		case 'C':
		return dht11_data[2];
		case 'F':
		return (int)((dht11_data[2] * 9.0/5) + 32);
		default:
		return dht11_data[2];
	}
}

void prepare_data_to_display(char *result, char data_type)
{
	int error = dht11_read_data();
	if(error)
	{
		sprintf(result, "Err%d", error);
		return;
	}
	int data = dht11_get_data(data_type);
	if(data / 100)
	{
		sprintf(result, "%d%c", data, data_type);
	}
	else if(data / 10)
	{
		sprintf(result, "D%d%c", data, data_type);
	}
	else
	{
		sprintf(result, "DD%d%c", data, data_type);
	}
}