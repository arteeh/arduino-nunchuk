#include <Nunchuk.h>

/*

Variables (unsigned 16 bit) you can use:

thumbStickX	-	Thumbstick horizontal value
thumbStickY	-	Thumbstick vertical value
accelerationX	-	Accelerometer data. You'll see that these numbers are high when you slam your nunchuk.
accelerationY	-	'
accelerationZ	-	'
cButton		-	C button, 1 when pressed, 0 when not
zButton		-	Z button, 1 when pressed, 0 when not

I made a quick function for simply reading the thumbstick. stickDir() returns a number:
1		-	Up
2		-	Right
3		-	Down
4		-	Left

*/

void setup()
{
  // Initialize the Nunchuk library
  nunchukInit();
}

void loop()
{
  nunchukUpdate();
  
  // Is the C button pressed?
  if(cButton)
  {
    // Yup
  }
  else
  {
    // Nope
  }
  
  if(stickDir() == 1)
  {
    // The thumbstick is pointed upwards.
  }
  
  
  delay(100);
}

