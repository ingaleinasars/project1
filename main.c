#include <stdio.h>

char encryptRotation(char *message, int index, const int key);

int main()
{
    int index = 0; 
    const int key = 12; //key is the amount of rotation - Caesar Cipher
    char message[] = "ALLIE IS COOL";
    
    printf("key = %d\n", key);
    printf("message to encrypt is: %s\n", message);
    
    encryptRotation(message, index, key);
    printf("encrypted message using rotation is: %s\n", message);
    
    
    return 0; 
}

char encryptRotation(char *message, int index, const int key)
{
    for(index = 0; message[index] !=0; index++)
       {
           if (message[index] > 64 && message[index] < 91)
           {
               message[index] = ((message[index] - 65) + key) %26 + 65;
           }
           
           else 
           {
               
           }
    
         
    }
    return message[index];
  } 


    
    
// did decrypt and encrypt codes separately in separate projects. got them working. next step to implement as functions
    
    

