#ifndef NUNCHUCK_H
#define NUNCHUCK_H

/***************************************************************************************
				     INCLUSIONS
***************************************************************************************/

#include <Wire.h>
#include <Arduino.h>

/***************************************************************************************
				      VARIABLES
***************************************************************************************/

extern uint16_t thumbStickX;
extern uint16_t thumbStickY;
extern uint16_t accelerationX;
extern uint16_t accelerationY;
extern uint16_t accelerationZ;
extern uint16_t cButton;
extern uint16_t zButton;

/***************************************************************************************
				FUNCTION DECLARATIONS
***************************************************************************************/

void nunchukInit();
void nunchukUpdate();
uint8_t stickDir();

#endif //NUNCHUCK_H
