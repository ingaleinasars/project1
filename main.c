/* THIS COMMENT NEEDS TO DESCRIBE THE HIGH-LEVEL OPERATION OF THE PROGRAM + 
INCLUDE USER-INTERFACE NOTES IE HOW USER PICKS BETWEEN ACTIONS. 
INCLUDE NEED TO USE TERMINAL. IE TYPE CD /PROJECTS/PROJECT1/ ENTER
LS ENTER ./A.OUT ENTER THEN FOLLOW COMMANDS PRINTED TO TERMINAL */

#include <stdio.h>

/* EXPLAIN FUNCTIONS INDIVIDUALLY BUT BRIEFLY AS FULL DESCRIPTION 
GIVEN LATER */
char encryptRotation(char *message, int index, int encryptRotKey);
char decryptRotation(char *message, int index, int decryptRotKey);
char encryptSubstitution(char *message, int index, char *key);
char decryptSubstitution(char *message, int index, char *key);

int main()
{
    /*char is short for character. It is the data type that holds
    one character (letter, number etc) of data. Here the variable 
    'choice' is initialised to be of data type 'char'*/
    char choice; 
    
    /*the do while loop  executes the following code at least once 
    with the condition being tested at the end. The loop only repeats
    if the condition is TRUE, otherwise the loop quits executing.*/
    do  
    {
        
    //MENU TO SELECT 
        printf("Please select an option: \n");
        printf("'a' encryption of code using rotation cipher \n");
        printf("'b' decryption of code using rotation cipher \n");
        printf("'c' encryption of code using substitution cipher \n");
        printf("'d' decryption of code using substitution cipher \n");
        printf("Enter a b c OR d for selection: \n");
    
        
        scanf("%c", &choice); 
     
       /* HOW DOES SWITCH CASE WORK ??*/
        switch(choice)
        {
            case 'a': 
                {
                    int index = 0;
                    int encryptRotKey;
                    char message[1000];
                    
               
                    printf("create a message to encrypt: ");
                    scanf(" %[^\n]s", message);        // the name of an array is a pointer to the first element of an array therefore no &
                    printf("create a key between 1 and 26: ");
                    scanf("%d", &encryptRotKey); 
                    
                    
                    encryptRotation(message, index, encryptRotKey);
                    printf("encrypted message is: %s \n", message);
                    
                    break;
                }
            case 'b':
                {
                    int index = 0;
                    int decryptRotKey;
                    char message[500];
                    
                    printf("create a key between 1 and 26: ");
                    scanf("%d", &decryptRotKey);
                    printf("create a message to decrypt: ");
                    scanf(" %[^\n]s", message);
                    
                    decryptRotation(message, index, decryptRotKey);
                    printf("decrypted message using rotation is: %s\n", message);
                    
                    break;
                }
            case 'c':
                {
                    int index = 0;
                    char key[26];
                    char message[500];
                    
                    printf("Enter a key for substitution encryption: ");
                    scanf("%s", key);
                    printf("Enter a message to encrypt using substitution: "); //PLEASE GET MILK AT THE SHOPS
                    scanf(" %[^\n]s", message);
                    
                    encryptSubstitution(message, index, key);
                    printf("encrypted message is: %s\n", message);
                    
                    break;                
                }
            case 'd':
                {
                    int index = 0;
                    char key[26]; //KXVMCNOPHQRSZYIJADLEGWBUFT for "QWERTY" key
                    char message[500]; //HSTQLT UTZ DOSA QZ ZIT LIGHL
                    
                    printf("Enter a key for substitution decryption: ");
                    scanf("%s", key);
                    printf("Enter a message to decrypt using substitution: ");
                    scanf(" %[^\n]s", message);
                    
                                  
                    decryptSubstitution(message, index, key);
                    printf("decrypted message is: %s\n", message);
                    
                    break;                
                }
            default:
                {
                    printf("An error has occured, please enter a b c OR d \n");
                    break;
                }
    
        }
    }
        while(choice < 97 || choice > 100);
        return 0;
           
}
/* */
char encryptRotation(char *message, int index, int encryptRotKey)
{
    for(index = 0; message[index] !=0; index++)
       {
           if (message[index] > 64 && message[index] < 91)
           {
               message[index] = ((message[index] - 65) + encryptRotKey) %26 + 65;
           }
           
           else 
           {
               
           }
    
         
    }
    return message[index];
  } 
  
  char decryptRotation(char *message, int index, int decryptRotKey)
  {
      for(index = 0; message[index] != 0; index ++)
      {
          if (message[index] > 64 && message[index] < 91)
          {
              message[index] = ((message[index] - 65) - decryptRotKey + 26) %26 + 65;
          }
          else 
          {
              
          }
      }
      return message[index];  
  }

  char encryptSubstitution(char *message, int index, char *key)
  {
      for (index = 0; message[index] != 0; index ++)
      {
          switch(message[index])
          {
            case 'A':
                message[index] = key[0];
                break;
            case 'B':
                message[index] = key[1];
                break;
            case 'C':
                message[index] = key[2];
                break;
            case 'D':
                message[index] = key[3];
                break;
            case 'E':
                message[index] = key[4];
                break;
            case 'F':
                message[index] = key[5];
                break;
            case 'G':
                message[index] = key[6];
                break;
            case 'H':
                message[index] = key[7];
                break;
            case 'I':
                message[index] = key[8];
                break;
            case 'J':
                message[index] = key[9];
                break;
            case 'K':
                message[index] = key[10];
                break;
            case 'L':
                message[index] = key[11];
                break;
            case 'M':
                message[index] = key[12];
                break;
            case 'N':
                message[index] = key[13];
                break;
            case 'O':
                message[index] = key[14];
                break;
            case 'P':
                message[index] = key[15];
                break;
            case 'Q':
                message[index] = key[16];
                break;
            case 'R':
                message[index] = key[17];
                break;
            case 'S':
                message[index] = key[18];
                break;
            case 'T':
                message[index] = key[19];
                break;
            case 'U':
                message[index] = key[20];
                break;
            case 'V':
                message[index] = key[21];
                break;
            case 'W':
                message[index] = key[22];
                break;
            case 'X':
                message[index] = key[23];
                break;
            case 'Y':
                message[index] = key[24];
                break;
            case 'Z':
                message[index] = key[25];
            default:
                break;
          }
      }
      return message[index];
  }
  
  char decryptSubstitution(char *message, int index, char *key)
  {
      for(index = 0; message[index] != 0; index ++)
      {
          switch(message[index])
          {
            case 'A':
                message[index] = key[0];
                break;
            case 'B':
                message[index] = key[1];
                break;
            case 'C':
                message[index] = key[2];
                break;
            case 'D':
                message[index] = key[3];
                break;
            case 'E':
                message[index] = key[4];
                break;
            case 'F':
                message[index] = key[5];
                break;
            case 'G':
                message[index] = key[6];
                break;
            case 'H':
                message[index] = key[7];
                break;
            case 'I':
                message[index] = key[8];
                break;
            case 'J':
                message[index] = key[9];
                break;
            case 'K': 
                message[index] = key[10];
                break;
            case 'L':
                message[index] = key[11];
                break;
            case 'M':
                message[index] = key[12];
                break;
            case 'N':
                message[index] = key[13];
                break;
            case 'O':
                message[index] = key[14];
                break;
            case 'P':
                message[index] = key[15];
                break;
            case 'Q':
                message[index] = key[16];
                break;
            case 'R':
                message[index] = key[17];
                break;
            case 'S':
                message[index] = key[18];
                break;
            case 'T':
                message[index] = key[19];
                break;
            case 'U':
                message[index] = key[20];
                break;
            case 'V':
                message[index] = key[21];
                break;
            case 'W':
                message[index] = key[22];
                break;
            case 'X':
                message[index] = key[23];
                break;
            case 'Y':
                message[index] = key[24];
                break;
            case 'Z':
                message[index] = key[25];
                break;
            default:
                break;
          }
      }
      return message[index];
  }

