/*
 * SegmentDisplay.h
 *
 * Created: 06.11.2023 19:47:48
 *  Author: calmeyweb
 */ 


#ifndef SEGMENTDISPLAY_H_
#define SEGMENTDISPLAY_H_

#include "Config.h"

#include <avr/io.h>
#include <util/delay.h>

//Redefine pinout of segment display here for custom setup
//LEDS
#define A_LED		PORTB5
#define B_LED		PORTB3
#define C_LED		PORTB6
#define D_LED		PORTB1
#define E_LED		PORTB2
#define F_LED		PORTB4
#define G_LED		PORTB7
#define PORT_LED	PORTB
#define DDR_LED		DDRB
//DIGITS
#define D1			PORTD4
#define D2			PORTD5
#define D3			PORTD6
#define D4			PORTD7
#define PORT_DIGITS	PORTD
#define DDR_DIGITS	DDRD

#define segment_setup(led, port, ddr) \
port |= (0<<led); \
ddr |= (1<<led)

#define digit_setup(digit, port, ddr) \
port |= (0<<digit); \
ddr |= (1<<digit)

#define segment_on(led, port) \
port |= (1<<led)

#define segment_off(led, port) \
port &= ~(1<<led)

#define digit_on(digit, port) \
port |= (1<<digit)

#define digit_off(digit, port) \
port &= ~(1<<digit)

uint8_t SYMBOLS[15][8];

void segment_display_setup();

void change_segment_state(uint8_t display_map[]);

void write_symbol(char symbol);

void write_digits(char *symbols);

#endif /* SEGMENTDISPLAY_H_ */