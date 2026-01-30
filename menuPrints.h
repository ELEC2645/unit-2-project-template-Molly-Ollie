/*Main Menu*/
 void main_menu(void);            /* runs in the main loop */
 void print_main_menu(void);      /* output the main menu description */
 int  get_user_input(void);       /* get a valid integer menu choice */
 void select_menu_item(int input);/* run code based on user's choice */
 void go_back_to_main(void);      /* wait for 'b'/'B' to continue */
 int  is_integer(const char *s);  /* validate integer string */


/*Scaling Menu*/
 void menu_unit_conversion(void);            /* runs in the main loop */
 void print_unit_conversion(void);
 int get_user_input_unit(void);
 void select_menu_item_unit(int input);


/* Scaling Shape Menu*/
//static void menu_scale_shape(void);            /* runs in the main loop */

/* Scaling File Menu*/
//static void menu_scale_file(void);            /* runs in the main loop */
