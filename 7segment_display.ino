/* Include the library:*/
#include <TM1637Display.h>
/* Define the connections pins:*/
#define CLK 2
#define DIO 3
/* Create display object of type TM1637Display:*/
TM1637Display display = TM1637Display(CLK,
DIO);
/* Create degree Celsius symbol:*/
const uint8_t celsius[] =
{
 SEG_A | SEG_B | SEG_F | SEG_G, /* Circle*/
 SEG_A | SEG_D | SEG_E | SEG_F /* C*/
};
void setup() /* Clear the display:*/
{
 display.clear();
 delay(1000);
}
void loop() /* Set the brightness 0-7*/
{
 display.setBrightness(4);
 /* Show counter:*/
 int i;
 for (i = 0; i < 101; i++)
 {
 display.showNumberDec(i);
 delay(50);
 }
 delay(1000);
 display.clear();
 /* Display temperature as example*/
 int temperature = 24;
/* display.showNumberDec(arg_1, arg_2, arg_3,
arg_4)
 arg_1 -> Number of type integer. Values up
to 9999.
 arg_2 -> True/false. Display leading zeroes
for values up to 999. Default value is false;
 arg_3 -> Correspond to the number of digits
to be displayed.
 arg_4 -> Position of the least significant
digit (0 – leftmost, 3 – rightmost).*/
display.showNumberDec(temperature, false, 2,0);
/* display.setSegments(arg_1, arg_2, arg_3)
 arg_1 -> Segment information
 arg_2 -> Number of digits to be modified
(0-4)
 arg_3 -> Position from which to print (0 –
leftmost, 3 – rightmost)*/
 display.setSegments(celsius, 2, 2);
 delay(1000);
 while(1);
}
