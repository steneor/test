#include <16F690.h>
//#device ADC=10
#use delay(internal=8000000)
//#use FIXED_IO( A_outputs=PIN_A0 )
#use rs232(baud=9600,xmit=PIN_B7,rcv=PIN_B5,bits=8,ERRORS)

