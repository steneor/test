#include <main.h>
#define StQ PIN_B4
#define Q1 PIN_C4
#define Q2 PIN_C5
#define Q3 PIN_C6
#define Q4 PIN_C7
#define REBOOT PIN_C0
#define RESET PIN_C1
#define TEST PIN_C2

int8 code;
short sleep_mode;   // global flag to send processor into sleep mode



#INT_RB
void  RB4_isr(void) {   // sortie du mode sleep
   disable_interrupts(INT_RB4);
   disable_interrupts(GLOBAL);
   //output_high(PIN_C2);

   //printf("Attente signal DTMF \n\r");
}

int read_dtmf(){
   int dtmf;
   dtmf = input(Q1) + 2 * input(Q2) + 4 * input(Q3) + 8 * input(Q4);
   return (dtmf);

}

void main()
{
   output_low(REBOOT);
   output_low(RESET);

   sleep_mode=FALSE;          // init sleep flag

//   ext_int_edge(L_TO_H);      // init interrupt triggering for button press
   

//   enable_interrupts(INT_RB4);
//   enable_interrupts(GLOBAL);

   while(TRUE)
   {
//      printf("Mise en veillle, reveille par IT RB4\n\r");
//      ext_int_edge(L_TO_H);      // init interrupt triggering for button press
//      enable_interrupts(INT_RB4);
//      enable_interrupts(GLOBAL);
//      sleep();
//      printf("Sortie de veille \n\r");
      printf("Attente signal DTMF \n\r");
      delay_ms(20);
      while ( !input(StQ) );       // waits for StQ
      printf("Lecture code DTMF\n\r");
      delay_ms(20);
      code = read_dtmf();
      printf("Code dtmf recu: %u \n\r",code);
      if (code == 5){  // reboot à chaud ...
         output_high(REBOOT);
         printf("reboot \n\r");
         delay_ms(1000);
         output_low(REBOOT);
      }
      if (code == 10){  // reset hard touche 0...
         output_high(RESET);
         printf("reset hard !!!\n\r");
         delay_ms(1000);
         output_low(RESET);
      }
      if (code == 1){  // reboot à chaud ...
         output_high(TEST);
         printf("TEST \n\r");
         delay_ms(1000);
         output_low(TEST);
      }
         delay_ms(1000);

   }
}
