/*
 * IL.h
 *
 *  Created on: Apr 13, 2019
 *      Author: Stud
 */

#ifndef IL_H_
#define IL_H_



void initPort(void);
void Blink(int LED);

void Normal_Mode(int LED, int btn);
int LC_Mode(int LED, int btn);
int Hazard_Mode();
int LEDs_Correction(int LED);
void key_Select();


/*typedef struct state {
	unsigned int DefaultMode = 0;
	unsigned int NormalMode = 1;
	unsigned int LaneChangeMode = 2;
	unsigned int HazardMode = 3;
};*/


#endif  IL_H_ 
