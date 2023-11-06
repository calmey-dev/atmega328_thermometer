/*
 * SegmentDisplay.c
 *
 * Created: 06.11.2023 19:47:33
 *  Author: calmeyweb
 */ 
#include "SegmentDisplay.h"

uint8_t SYMBOLS[15][8] =
{
	{1, 1, 1, 1, 1, 1, 0, 0},	//0
	{0, 1, 1, 0, 0, 0, 0, 0},	//1
	{1, 1, 0, 1, 1, 0, 1, 0},	//2
	{1, 1, 1, 1, 0, 0, 1, 0},	//3
	{0, 1, 1, 0, 0, 1, 1, 0},	//4
	{1, 0, 1, 1, 0, 1, 1, 0},	//5
	{1, 0, 1, 1, 1, 1, 1, 0},	//6
	{1, 1, 1, 0, 0, 0, 0, 0},	//7
	{1, 1, 1, 1, 1, 1, 1, 0},	//8
	{1, 1, 1, 1, 0, 1, 1, 0},	//9
	{1, 1, 0, 0, 0, 1, 1, 0},	//Celsius
	{1, 0, 0, 0, 1, 1, 1, 0},	//Fahrenheit
	{0, 0, 0, 0, 0, 0, 0, 0},	//Disabled
	{1, 0, 0, 1, 1, 1, 1, 0},	//E
	{0, 0, 0, 0, 1, 0, 1, 0}	//r
};

void segment_display_setup()
{
	PORT_LED |= (0<<A_LED)|(0<<B_LED)|(0<<C_LED)|(0<<D_LED)|(0<<E_LED)|(0<<F_LED)|(0<<G_LED);
	DDR_LED |= (1<<A_LED)|(1<<B_LED)|(1<<C_LED)|(1<<D_LED)|(1<<E_LED)|(1<<F_LED)|(1<<G_LED);
	
	PORT_DIGITS |= (0<<D1)|(0<<D2)|(0<<D3)|(0<<D4);
	DDR_DIGITS |= (1<<D1)|(1<<D2)|(1<<D3)|(1<<D4);
}

void change_segment_state(uint8_t display_map[])
{
	//Led A
	if(display_map[0] == 1)
	{
		segment_on(A_LED, PORT_LED);
	}
	else 
	{
		segment_off(A_LED, PORT_LED);
	}
	//Led B
	if(display_map[1] == 1)
	{
		segment_on(B_LED, PORT_LED);
	}
	else
	{
		segment_off(B_LED, PORT_LED);
	}
	//Led C
	if(display_map[2] == 1)
	{
		segment_on(C_LED, PORT_LED);
	}
	else
	{
		segment_off(C_LED, PORT_LED);
	}
	//Led D
	if(display_map[3] == 1)
	{
		segment_on(D_LED, PORT_LED);
	}
	else
	{
		segment_off(D_LED, PORT_LED);
	}
	//Led E
	if(display_map[4] == 1)
	{
		segment_on(E_LED, PORT_LED);
	}
	else
	{
		segment_off(E_LED, PORT_LED);
	}
	//Led F
	if(display_map[5] == 1)
	{
		segment_on(F_LED, PORT_LED);
	}
	else
	{
		segment_off(F_LED, PORT_LED);
	}
	//Led G
	if(display_map[6] == 1)
	{
		segment_on(G_LED, PORT_LED);
	}
	else
	{
		segment_off(G_LED, PORT_LED);
	}
	//Led DP
	/*if(display_map[7] == 1)
	{
		segment_on(DP_LED, PORT_LED);
	}
	else
	{
		segment_off(DP_LED, PORT_LED);
	}*/
}

void write_symbol(char symbol)
{
	switch(symbol)
	{
		case '0':
			change_segment_state(SYMBOLS[0]);
			break;
		case '1':
			change_segment_state(SYMBOLS[1]);
			break;
		case '2':
			change_segment_state(SYMBOLS[2]);
			break;
		case '3':
			change_segment_state(SYMBOLS[3]);
			break;
		case '4':
			change_segment_state(SYMBOLS[4]);
			break;
		case '5':
			change_segment_state(SYMBOLS[5]);
			break;
		case '6':
			change_segment_state(SYMBOLS[6]);
			break;
		case '7':
			change_segment_state(SYMBOLS[7]);
			break;
		case '8':
			change_segment_state(SYMBOLS[8]);
			break;
		case '9':
			change_segment_state(SYMBOLS[9]);
			break;
		case 'C':
			change_segment_state(SYMBOLS[10]);
			break;
		case 'F':
			change_segment_state(SYMBOLS[11]);
			break;
		case 'D':
			change_segment_state(SYMBOLS[12]);
			break;
		case 'E':
			change_segment_state(SYMBOLS[13]);
			break;
		case 'r':
			change_segment_state(SYMBOLS[14]);
			break;
		default:
			change_segment_state(SYMBOLS[12]);
			break;
	}
}

void write_digits(char *symbols)
{
	int delay_time = 5;
	digit_on(D1, PORT_DIGITS);
	write_symbol(symbols[0]);
	_delay_ms(delay_time);
	digit_off(D1, PORT_DIGITS);
	
	digit_on(D2, PORT_DIGITS);
	write_symbol(symbols[1]);
	_delay_ms(delay_time);
	digit_off(D2, PORT_DIGITS);
	
	digit_on(D3, PORT_DIGITS);
	write_symbol(symbols[2]);
	_delay_ms(delay_time);
	digit_off(D3, PORT_DIGITS);
	
	digit_on(D4, PORT_DIGITS);
	write_symbol(symbols[3]);
	_delay_ms(delay_time);
	digit_off(D4, PORT_DIGITS);
}