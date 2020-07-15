
//Listing 13.7 - Using the switch statement to execute a menu system; page 314
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DELAY 150000000

int menu(void);
void delay(void);

int main(void)
{
    int command = 0;
    command = menu();  //first display/call from menu

    while(command != 5)
    {
        //get user selection and branch based on input
        switch(command)
        {
            case 1:
                {
                puts("\n\t\t-----> Executing task A.");
                delay();
                break;
                }
            case 2:
                {
                puts("\n\t\t-----> Executing task B.");
                delay();
                break;
                }
            case 3:
                {
                puts("\n\t\t-----> Executing task C.");
                delay();
                break;
                }
            case 4:
                {
                puts("\n\t\t-----> Executing task D.");
                delay();
                break;
                }
            case 5:    // Exit program
                {
                // This "puts" here doesn't get executed because loop already
                // knows that "5" was selected and it exits without executing
                // the statements here. You would need to set up loop a little
                // different if you want statements to here to actually execute
                puts("\n\t\t-----> Exiting program now....");
                delay();
                break;
                }
            default:
                {
                puts("\n\t\t-----> Invalid choice. Try again.");
                delay();
                break;
                }
        }  //end of switch

        command = menu(); //next display/call from menu

    }  //end of while

    puts("\n\t\t-----> Exiting program now....\n\n");
    return 0;
}

//displays a menu and inputs user's selection
int menu(void)
{

    //int reply;
    char reply2 = ' ';

    fflush(stdin);  //NEED FFLUSH TO CLEAR BUFFER IF USER ENTERS INVALID CHOICE
                    // SUCH AS A LETTER INSTEAD OF INTEGER OR OTHERWISE
                    // PROGRAM GETS CAUGHT IN A FUNKY LOOP AND BOMBS
    puts("\n******************");
    puts("\nEnter 1 for task A.");
    puts("\nEnter 2 for task B.");
    puts("\nEnter 3 for task C.");
    puts("\nEnter 4 for task D.");
    puts("\nEnter 5 to exit program");

    // MUST use "&" because an address is required for scanf command and you
    //  need the address of variable reply
    //
    //NOTE: THIS PROGRAM BOMBS IF THE USER ENTERS A CHARACTER INSTEAD OF A NUMBER
    //  HOW TO FIX??? USE FFLUSH TO FLUSH INPUT STREAM PRIOR TO REDISPLAY OF
    //  MENU FOR INVALID MENU CHOICES
    //
    //scanf("%1d", &reply);
    scanf("%c", &reply2);

    if(isdigit(reply2))
    {
        printf("\nThe menu choice entered on screen is the number: %c", reply2);
    }
    else
    {
        printf("\nThe menu choice entered on screen is the character: %c", reply2);
    }


    printf("\nThe menu choice entered on screen is: %c", reply2);
    //To convert a character to an integer
    //..from webpage - http://stackoverflow.com/questions/628761/character-to-integer-in-c
    //char c = '5';
    //int x = c - '0';
    int reply = reply2 - '0';   //<-- not sure why this works here
    return reply;               //<-- now returning an integer

}

void delay(void)
{
    long x;
    for(x=0; x<DELAY; x++)
        ;
    // this function basically does nothing but have program wait

}
