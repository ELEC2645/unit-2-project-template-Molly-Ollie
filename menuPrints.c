#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "menuPrints.h"
#include "funcs.c"

/* Main Menu Option*/

 void main_menu(void)
{
    print_main_menu();
    {
        int input = get_user_input();
        select_menu_item(input);
    }
}

 void print_main_menu(void)
{
    printf("---------------------------------------------\n"
           "\n      -Main menu-         \n\n"
           "\t1. Unit Scaling \t\t\n"
           "\t2. Pattern Scaling: Shape \t\t\n"
           "\t3. Pattern Scaling: File\t\t\n"
           "\t4. Exit\t\t\t\t\n\n");
    printf("---------------------------------------------\n");
}

 int get_user_input(void)
{
    enum { MENU_ITEMS = 4 };   /* 1 to 3 = items, 4 = Exit */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

 void select_menu_item(int input)
{
    switch (input) {
        case 1:
            menu_unit_conversion();
            break;
        case 2:
            menu_scale_shape();
            break;
        case 3:
            //menu_scale_file();
            go_back_to_main();
            break;
        default:
            printf("Bye!\n");
            exit(0);
    }
}

 void go_back_to_main(void)
{
    char buf[64];
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
    } while (!(buf[0] == 'b' || buf[0] == 'B') || buf[1] != '\0');
}
/* Return 1 if s is an optional [+/-] followed by one-or-more digits, else 0. */
 int is_integer(const char *s)
{
    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}



/* UNIT CONVERSION MENU*/
 void menu_unit_conversion(void)
{
    print_unit_conversion();
    char buf[128] = ""; //setting the buffer = empty to ensure no remaining value from last use
    get_user_input_unit(buf); 
    select_menu_item_unit(buf);
    }

 void print_unit_conversion(void)
{
    printf("---------------------------------------------\n"
           "\n\t         -Unit Conversion-         \n"
           "\n\t To restart page, press 'r'\t\t\n"
            "\n\t To exit page, press 'b'\t\t\n");
}

char* get_user_input_unit(char *buf)
{
    int valid_input = 0;
    do {
        printf("\t\t\t\t\t\t\nEnter initial measurement in inches:\t");
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

 void select_menu_item_unit(const char *buf)
{
    if (*buf == 'b'){
        main_menu();
    } else if (*buf == 'r'){ 
        menu_unit_conversion();
    }else{
        int numberTrue = is_integer(buf) ;  //ensures user has entered a number 
        double measurement = atof(buf);
        if (numberTrue){
            char unit[128] = get_unit();
            unit_convert(measurement, unit); //if a valid numerical input is entered, the code will move to the functionality
            menu_unit_conversion();
        }else{printf("Measurement error! Please try again");}
    }
}


/*scale shape MENU*/
void menu_scale_shape(void)
{
    print_scale_shape();
    char buf[128] = ""; //setting the buffer, reusing the buffer local variable for readability
    get_user_input_shape(buf); 
    select_menu_item_shape(buf);
    }

 void print_scale_shape(void)
{
    printf("---------------------------------------------\n"
           "\n\t         -Shape Scalling-         \n"
           "\n\t To restart page, press 'r'\t\t\n"
            "\n\t To exit page, press 'b'\t\t\n");
}

char* get_user_input_shape(char *buf)
{
    int valid_input = 0;
    do {
        printf("\t\t\nSelect shape:"
               "\n for a square or rectangle, press 's'\n"
               "\n for a circle, press 'c'\n"
               "\n for a triangle, press 't'\n");
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

void select_menu_item_shape(const char *buf)
{
    if (*buf == 'b'){
        main_menu();
    } else if (*buf == 'r'){ 
        menu_scale_shape();
    }else if (*buf == 's') {
        printf("square");
    }else if (*buf == 'c') {
        printf("circle functionality");
    }else if (*buf == 't') {
        printf("triangle functionality \n");
    }else{
        printf("please enter a valid option!");
        char buf[128] = "";
        get_user_input_shape(buf);
    }
}



