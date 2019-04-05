#include "main.h"
#include "auton.h"

 void autonomous() {
   motor_tare_position(angler);
   for(int i = 12; i <= 14; i++) {
     motor_set_brake_mode(i, E_MOTOR_BRAKE_HOLD);
   }
   motor_set_brake_mode(20, E_MOTOR_BRAKE_HOLD);
   switch(auton_select){
     case 1: close_red(); break;
     case 2: close_blue(); break;
     case 3: backred(); break;
     case 4: backblue(); break;
     case 5: skills_auton(); break;
   }
   backred();
   // skills_auton();
   // test();
   // display();
   for(int i = 12; i <= 14; i++) {
     motor_set_brake_mode(i, E_MOTOR_BRAKE_COAST);
   }
   motor_set_brake_mode(20, E_MOTOR_BRAKE_COAST);
}
