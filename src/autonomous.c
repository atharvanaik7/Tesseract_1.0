#include "main.h"
#include "auton.h"

 void autonomous() {
   motor_tare_position(angler);
   brakeMode();
   switch(auton_select){
     case 1: close_red(); break;
     case 2: close_blue(); break;
     case 3: backred(); break;
     case 4: backblue(); break;
     case 5: skills_auton(); break;
   }
   backblue();
   // skills_auton();
   // test();
   // display();
   coastMode();
}
