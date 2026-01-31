#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "funcs.h"
#include "funcs.c"

float unit_convert(int measurement, char *unit){

    measurement = (float) measurement;  //ensuring variables are in the correct format
    char first_unit = tolower(*unit);
    float value = 0;

    if (first_unit == 'm'){  //if-else to select correct calculation
        value = measurement * 25.4;
        printf("%d inches is %f mm", measurement, value);
    }else if (first_unit == 'c'){
        value = measurement * 2.54;
        printf("%d inches is %f cm", measurement, value);
    }else{
        printf("hmmmmmm error has occured. Please try again!");
     }
}


char* get_unit()
    {
        int valid_input = 0;
        char buf[128] = []
        do {
            printf("\t\t\t\t\t\t\nEnter the output unit\t");
            if (!fgets(buf, sizeof(buf), stdin)) {
              // EOF or error; bail out gracefully
             puts("\nInput error. Exiting.");
                exit(1);
         }else {     
         // strip trailing newline
              buf[strcspn(buf, "\r\n")] = '\0';
              valid_input = 1;
        }
    } while (!valid_input);
    return buf;
}

void menu_item_2(void) {
    printf("\n>> Menu 2\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
}

void menu_item_3(void) {
    printf("\n>> Menu 3\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 3 */
}

void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}