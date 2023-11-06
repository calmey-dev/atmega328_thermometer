/*
 * DHT11SimpleLibrary.h
 *
 * Created: 04.11.2023 13:57:13
 *  Author: calmeyweb
 */ 


#ifndef DHT11SIMPLELIBRARY_H_
#define DHT11SIMPLELIBRARY_H_

#include "Config.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define DHT11		PORTD3
#define DHT11_PORT	PORTD
#define DHT11_PIN	PIND
#define DHT11_DDR	DDRD

unsigned char dht11_data[5];

void dht11_setup();

int dht11_read_data();

int dht11_get_data(char data);

void prepare_data_to_display(char *result, char data_type);

#endif /* DHT11SIMPLELIBRARY_H_ */