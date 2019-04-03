#include "nunchuk.h"

#define ADDRESS 0x52

// Declare and set variables
uint16_t thumbStickX = 0;
uint16_t thumbStickY = 0;
uint16_t accelerationX = 0;
uint16_t accelerationY = 0;
uint16_t accelerationZ = 0;
uint16_t cButton = 0;
uint16_t zButton = 0;

void nunchukInit()
{
	// Init the Wire library
	Wire.begin();
	
	// Initialize the nunchuk without encryption:
	// START, 0xF0, 0x55, STOP, START, 0xFB, 0x00, STOP
	Wire.beginTransmission(ADDRESS);
	Wire.write(0xF0);
	Wire.write(0x55);
	Wire.endTransmission();
	Wire.beginTransmission(ADDRESS);
	Wire.write(0xFB);
	Wire.write(0x00);
	Wire.endTransmission();
}

void nunchukUpdate()
{
	// Array that will contain incoming data
	uint8_t values[6];

	// Dare the nunchuk to send something
	Wire.beginTransmission(ADDRESS);
	Wire.write(0x00);
	Wire.endTransmission();
	
	/*
	Request 6 bytes of data.
	1st byte = thumbstick X
	2nd byte = thumbstick Y
	3rd byte = acceleration X
	4th byte = acceleration Y
	5th byte = acceleration Z
	6th byte = button
	*/
	Wire.requestFrom(ADDRESS, 6);

	// Place incoming bytes in values array
	for(uint8_t count = 0; Wire.available(); count++)
		values[count] = Wire.read();
	
	// Place values array bytes in the right variables
	thumbStickX	=	values[0];
	thumbStickY	=	values[1];
	
	accelerationX	=	values[2];
	accelerationY	=	values[3];
	accelerationZ	=	values[4];
	
	/*
	values[5]:
	0 = both pressed
	1 = c button pressed
	2 = z button pressed
	3 = none pressed
	
	Set button variables accordingly.
	*/
	cButton		=	0;
	zButton		=	0;
	switch(values[5])
	{
		case 0:
			cButton = 1;
			zButton = 1;
			break;
		case 1:
			cButton = 1;
			break;
		case 2:
			zButton = 1;
			break;
		case 3:
			break;
	}
}

/*
Return 1, 2, 3 or 4 when thumbstick points up, right, down or left respectively.
*/
uint8_t stickDir()
{
	if (thumbStickY > 188)
		return 1;
	else if (thumbStickX > 188)
		return 2;
	else if (thumbStickY < 68)
		return 3;
	else if (thumbStickX < 68)
		return 4;
	else
		return 0;
}
