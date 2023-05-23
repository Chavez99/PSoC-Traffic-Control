/* ========================================
 *
 * Copyleft by Shahariar,2015
 * All Rights Released
 * OPEN SOFTWARE, NO WARRENTY 
 *
 * DODGY BROTHERS C CODING Inc.  
 * Programmed With No Style, BUG may appear in Future !!!
 * Non-Precision Soft-Only Clock, will Lose around 12 sec a day, ( may vary for other PSoC chips)
 * ========================================
*/

// flag variable is a volatile global variable to check interrupt
#include <project.h>

int main()
{
    Simple_TL_Control_1_Count7_1_Start();
    CyGlobalIntEnable;
    
    for(;;)
    
    {
    }
}
          

/* [] END OF FILE */
