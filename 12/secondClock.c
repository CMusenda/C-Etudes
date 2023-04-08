#include <stdio.h>
#include <time.h>

long updateClockSeconds();
int main(){
//variables to store clock data
    long secondsSinceProgramStart;
    long timer;
//variables to store user input
    int inTime;
    int updatesPerSecond;
//user input request
    printf("Please enter a time in seconds: ");
    if(!scanf("%d", &inTime)){
        printf("ERROR: FAILED TO READ INPUT");
        return -1;
    }
    fflush(stdin);
    
    printf("How often should the program print per second: "); 
    if(!scanf("%d", &updatesPerSecond)){
        printf("ERROR: FAILED TO READ INPUT\n");            
        return -1;
    }
    fflush(stdin);
    char ch;
    printf("Press any ENTER to continue...");
    scanf("%c",&ch);
    fflush(stdin);
    secondsSinceProgramStart = updateClockSeconds();
    while(timer != inTime){
    timer = updateClockSeconds()-secondsSinceProgramStart;
    printf("%ld",timer);
    }
    printf("TIME ENTERED: %d\nUPDATES PER SECOND: %d\nSECONDS SINCE PROGRAM START: %ld\n", inTime,updatesPerSecond, secondsSinceProgramStart);
   
    return 0;
}
long updateClockSeconds(){
    clock_t ticks = clock();
    long secondsSinceProgramStart;
    secondsSinceProgramStart = ticks / CLOCKS_PER_SEC;
    return secondsSinceProgramStart;
}
