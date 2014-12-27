/*
 * lophilo.h
 *
 *  Created on: Jun 14, 2014
 *      Author: zhizhouli
 */

#ifndef LOPHILO_H_
#define LOPHILO_H_
#include <stdio.h>
//Functionality: Initial the broad
int init(void)
{
	printf("call init");
}
//Functionality: Control the led
//Argument:
//id: The id of led can be 0-3
//r: The red color of led
//g: The greem color of led
//b: The blue color of led
void led(int id, char r, char g, char b)
{
	printf("call led");
}

//Functionality: Control the IO port a
//Argument:
//id: use 0-26
//value: Can be 1 or 0
void ioa(int id, int value)
{
	printf("call ioa");
}

//Functionality: Control the IO port b
//Argument:
//id: use 0-26
//value: Can be 1 or 0
void iob(int id, int value)
{
	printf("call iob");
}

//Functionality: print the string to the console
//Argument:
//format:output format string
int print(const char* format, ...)
{
	printf("call print");
}

//Functionality: Sleep for seconds
//Argument:
//seconds The seconds for sleeping
unsigned int sleep(unsigned int seconds)
{
	printf("call sleep");
}

//Functionality: Sleep for micro seconds
//Argument:
//usecods: The micro seconds for sleeping
int usleep(unsigned int useconds)
{
	printf("call usleep");
}

#endif /* LOPHILO_H_ */
