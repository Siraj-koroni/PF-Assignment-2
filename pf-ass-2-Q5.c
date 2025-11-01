#include<stdio.h>
#include<string.h>
void reverseStr(char str[]){
 int len=strlen(str);
 for (int i = 0; i < len/2; i++)
 {
    int temp=str[i];
    str[i]=str[len-i-1];
    str[len -i-1] =temp; 
 }
 
}
void bitToggle(char *str){
   for (int i = 0; str[i]!='\0'; i++)
   {
     str[i]=~str[i];
   }
   
}
void encode(char *text){
  reverseStr(text);
  bitToggle(text);
}
void decode(char *text){
 bitToggle(text);
 reverseStr(text);
}
int main(){
 char message[100];
 printf("\n*********** TCS (Tranzum Courier Service) of Pakistan**************\n");
 printf("Encoding and Decoding Message system\n");
 printf("\nEnter your text: ");
 fgets(message,sizeof(message),stdin);

 encode(message);
 printf("\nEncoded message: ");
 for(int i=0; message[i]!='\0';i++){
   printf("%2x",(unsigned char)message[i]);
}
 decode(message);
 printf("\nDecoded message: %s",message);


return 0;
}
