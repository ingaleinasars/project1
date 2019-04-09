#include <stdio.h>
//write function to use to encrypt the message provided 
int encryptCode(char *message);

int main()
{
    char message[100]; //
    int index; 
    int key; //key is the amount of rotation - Caesar Cipher
    
    printf("Enter a message using upper case letters to be encrypted: ");
    scanf("%s", &message);
    printf("Enter a value for key: ");
    scanf("%d", &key);
    
    printf("key is equal to %d\n", key);
    printf("message to encrypt is %s\n", message);
    
    
    //do something 
    
    //exit main()
    return 0; 
}

int encryptCode(char *message)
    {
       
 `for(int index = 0; message[index] !=0; index++)
       {
           if (message[index] > 64 && message[index] < 91)
           {
               message[index] = (message[index] + k)(%26)
           }
           
           else 
           {
               
           }
    
      return message;     
    }
    //do function 
    //insert code to encrypt
    //print encrypted code badabing badaboom
    
    
    
// did decrypt and encrypt codes separately in separate projects. got them working. next step to implement as functions
    
    

