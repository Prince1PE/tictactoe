//  TODO
// Make sure the number values are constantly displayed
// Change scanf to fgets -- fgets doesnt work with int, alternate method used
// Offer user replay function -- good enough


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
void printlines()   //Prints the rows
{
   printf("\n");
   for (int i = 0; i < 3; i++)
   {
       printf("+---");
   }
   printf("+");
   printf("\n");
}



void printlines2()   //Prints the rows
{
   printf("\n");
   for (int i = 0; i < 3; i++)
   {
       printf("+---");
   }
   printf("+");
   printf("\n|");
}

void printTable2(char valueArray[9])
{
    int numArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printlines2();
    for (int i = 0; i < 9; i++)
    {
        if (valueArray[i] == '_')
        {
            printf(" %i |", i + 1);
        }
        else{
            printf(" %c |", valueArray[i]);
        }
        if (i == 2 || i == 5 || i == 8)
        {
            printlines2();
        }
        
    }
    
}

void printTable(char valueArray[9]) //Prints the columns with the relevent values
{
   printlines();
   printf("| %c | %c | %c |", valueArray[0], valueArray[1], valueArray[2]);
   printlines();
   printf("| %c | %c | %c |", valueArray[3], valueArray[4], valueArray[5]);
   printlines();
   printf("| %c | %c | %c |", valueArray[6], valueArray[7], valueArray[8]);
   printlines();
}
 

bool getInput(bool player1Turn, char valueArray[9])
{
   int loc;    //loc being where the user wants to enter their mark
   while (true)
   {
       printf("Where do you want to place your mark?: ");
       int args = scanf("%i", &loc);  //TODO: change this to fgets
       if (args < 1) // If a non integer charecter is detected
       {
          printf("Enter a number dummy\n"); 
          char dummy;   //Store buffered char in dummy vartiable
          scanf("%c", &dummy);
       }

       else if (loc < 1 || loc > 9) //Checks if it is within the valid range
       {
           printf("Enter a number between 1 and 9\n");
       }
       else if (valueArray[loc - 1] != '_')    //Checks to see if that space is free
       {
           printf("That spot is already taken\n");
       }
       else{
           break;
       }
   }
 
   if (player1Turn)
   {
       valueArray[loc - 1] = 'X';  //Places the mark
       player1Turn = false;        //Changes the turn
   }
   else
   {
       valueArray[loc - 1] = 'O';
       player1Turn = true;
   }
  
   return player1Turn;
}
 
void winMessege(char* winner)
{
   printf("***** %s has won the game*****\n", winner);
}
 
bool checkWin(bool player1Turn, char valueArray[9])
{
   //012
   //345
   //678
  
   char winner[9];
   if (player1Turn == false)
   {
       strcpy(winner, "Player 1");
   }
   else
   {
       printf("%i", player1Turn);
       strcpy(winner, "Player 2");
   }
   if (valueArray[0] != '_' && valueArray[0] == valueArray[1] && valueArray[1] == valueArray[2])   //Checks the top row and makes sure it is not all blanks
   {
       winMessege(winner);
       return true;
   }
 
   else if (valueArray[3] != '_' && valueArray[3] == valueArray[4] && valueArray[4] == valueArray[5]) //Checks the middle row
   {
       winMessege(winner);
       return true;
   }
 
   else if (valueArray[6] != '_' && valueArray[6] == valueArray[7] && valueArray[7] == valueArray[8]) //Checks the bottom row
   {
       winMessege(winner);
       return true;
   }
 
   else if (valueArray[0] != '_' && valueArray[0] == valueArray[3] && valueArray[3] == valueArray[6])  //Checks the left column
   {
      winMessege(winner);
      return true;
   }
  
   else if (valueArray[1] != '_' && valueArray[1] == valueArray[4] && valueArray[4] == valueArray[7])  //Checks the middle column
   {
       winMessege(winner);
       return true;
   }
  
   else if (valueArray[2] != '_' && valueArray[2] == valueArray[5] && valueArray[5] == valueArray[8])  //Checks the right column
   {
       winMessege(winner);
       return true;
   }
  
   else if (valueArray[2] != '_' && valueArray[2] == valueArray[4] && valueArray[4] == valueArray[6])  //Checks diagonal up
   {
       winMessege(winner);
       return true;
   }
 
   else if (valueArray[0] != '_' && valueArray[0] == valueArray[4] && valueArray[4] == valueArray[8])  //Checks diagonal down
   {
       winMessege(winner);
       return true;
   }
   else{
       return false;
   }
  
}
 
int main()
{
   printf("Below is the table, enter the coresponding values to win");
   printlines();
   printf("| 1 | 2 | 3 |");
   printlines();
   printf("| 4 | 5 | 6 |");
   printlines();
   printf("| 7 | 8 | 9 |");
   printlines();
   bool gameWon = false;
   bool player1Turn = true;
   char pos1 = '_', pos2 = '_', pos3 = '_', pos4 = '_', pos5 = '_', pos6 = '_', pos7 = '_', pos8 = '_', pos9 = '_'; //Sets a blank pos as _
   char ValueArray[9] = {pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9};
   int count = 0;
   while (gameWon == false && count < 9)
   {
       player1Turn = getInput(player1Turn, ValueArray);
       printTable(ValueArray);
       gameWon = checkWin(player1Turn, ValueArray);
       count ++;
   }
   if (count == 9)
   {
       printf("Looks like its a draw\n");
   }

    while (true)
    {

    int replay;
    printf("Do you want to play again?(1 for yes, 2 for no):");
    int args = scanf("%i", &replay);

    if (args < 1) // If a non integer charecter is detected
       {
          printf("Enter a number dummy\n"); 
          char dummy;   //Store buffered char in dummy vartiable
          scanf("%c", &dummy);
       }
    else if (replay == 1)
    {
        main();
    }
    else if (replay == 2)
    {
        break;
    }
    else
    {
        printf("Enter 1 or two\n"); //This shouldnt be reached ever
    }
    
    }
    

   //Maybe offer a replay
   return 0;
}


