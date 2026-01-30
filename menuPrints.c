#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "menuPrints.h"



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
    printf("\n         *Main menu*         \n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Unit Scaling 1\t\t\n"
           "\t2. Pattern Scaling: Shape 2\t\t\n"
           "\t3. Pattern Scaling: File\t\t\n"
           "\t4. Exit\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
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
            go_back_to_main();
            break;
        case 2:
            //menu_scale_shape();
            go_back_to_main();
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
    {
         int input = get_user_input_unit();
         select_menu_item_unit(input);
    }
}

 void print_unit_conversion(void)
{
    printf("\n         *Unit Scaliing*         \n");

    printf("\n"
            "\n to return to main menu, press 'B'"
            "\n to restart page, press 'R'"
           "\t\t\t\t\t\t\n"
           "\tEnter initial measurement in inches:\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
}

 int get_user_input_unit(void)
{
    char buf[128];
    int valid_input = 0;
    int value = 0;

     do {
        if (!fgets(buf, sizeof(buf), stdin)) {
            // EOF or error; bail out gracefully
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        value = (char)strtol(buf, NULL, 10);
        }
        
        while (!valid_input);
        return value;
}

 void select_menu_item_unit(int input)
{
    switch (input) {
        case 'e':
            char buf[64];
            if (!fgets(buf, sizeof(buf), stdin)) {
                puts("\nInput error. Exiting.");
                exit(1);
            }
            buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
            while (!(buf[0] == 'b' || buf[0] == 'B') || buf[1] != '\0');

        case 'B':
            //menu_scale_shape();
            break;
    }
}
