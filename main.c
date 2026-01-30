// ELEC2645 Unit 2 Project Template
// Command Line Application Menu Handling Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "menuPrints.h"
#include "menuPrints.c"

#include "funcs.h"
#include "funcs.c"

/* Prototypes mirroring the C++ version */

int main(void)
{
    /* this will run forever until we call exit(0) in select_menu_item() */
    for(;;) {
        main_menu();
    }
    /* not reached */
    return 0;
}
