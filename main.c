#include <stdio.h>

char encryptRotation(char *message, int index, const int encryptRotKey);
char decryptRotation(char *message, int index, const int decryptRotKey);
char encryptSubstitution(char *message, int index, char *key);
char decryptSubstitution(char *message, int index, char *key);
int main()
{
    //MENU TO SELECT 
    printf("Please select an option: \n");
    printf("1. encryption of code using rotation cipher \n");
    printf("2. decryption of code using rotation cipher \n");
    printf("3. encryption of code using substitution cipher \n");
    printf("4. decryption of code using substitution cipher \n");
    printf("Selection: \n");
    
    char choice; 
    scanf("%c", &choice); //WORK OUT HOW TO USE SCANF IN CHE
    
    switch(choice)
    {
        case '1': 
            {
                int index = 0;
                int encryptRotKey;
                char message[500];
                
                printf("create a key between 1 and 26: \n");
                scanf("%d\n", &encryptRotKey);
                printf("create a message to encrypt via rotation using key %d", encryptRotKey);
                scanf("%s\n", message);        
                printf("key = %d\n", encryptRotKey);
                printf("message to encrypt is: %s\n", message);
                
                encryptRotation(message, index, encryptRotKey);
                printf("encrypted message using rotation is: %s\n", message);
                
                break;
            }
        case '2':
            {
                int index = 0;
                const int decryptRotKey = 12;
                char message[] = "MXXUQ UE OAAX";
                printf("key = %d\n", decryptRotKey);
                printf("message to decrypt is: %s\n", message);
                
                decryptRotation(message, index, decryptRotKey);
                printf("decrypted message using rotation is: %s\n", message);
                
                break;
            }
        case '3':
            {
                int index = 0;
                char key[]="QWERTYUIOPASDFGHJKLZXCVBNM";
                char message[]="PLEASE GET MILK AT THE SHOPS";
                
                printf("message to encrypt is: %s\n", message);
                
                encryptSubstitution(message, index, key);
                printf("encrypted message is: %s\n", message);
                
                break;                
            }
        case '4':
            {
                int index = 0;
                char key[]="KXVMCNOPHQRSZYIJADLEGWBUFT";
                char message[]="HSTQLT UTZ DOSA QZ ZIT LIGHL";
                
                printf("message to decrypt is: %s\n", message);
                
                decryptSubstitution(message, index, key);
                printf("decrypted message is: %s\n", message);
                
                break;                
            }
        default:
            {
                
            }
    }
    
     
    
    return 0; 
}

char encryptRotation(char *message, int index, const int encryptRotKey)
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
  
  char decryptRotation(char *message, int index, const int decryptRotKey)
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

