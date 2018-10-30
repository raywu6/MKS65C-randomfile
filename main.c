#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   // for open
#include <unistd.h>  // for close/read/write

// Raymond Wu
// Systems p10
// open, read, write, close, /dev/random
// T 2018-10-30

int getRandomInt() {
    int retVal;

    int fd = open( "/dev/random", O_RDONLY );
    read( fd , &retVal , sizeof(int) );
    close(fd);

    return retVal;
}

int main() {

    int myArray[10];

    // load array
    for (int i=0 ; i<10 ; i++) 
        myArray[i] = getRandomInt();
    
    // print array
    for (int i=0 ; i<10 ; i++)
        printf("random %d: %d\n", i, myArray[i]);

    // write to file
    int fd = open( "myRandomInts.txt", O_CREAT | O_WRONLY, 0711 ); // octal impt!
    write( fd , myArray , 10*4 );
    close(fd);

    // read file into different array
    int verifyArray[10];

    fd = open( "myRandomInts.txt", O_RDONLY );
    read( fd , verifyArray , 10*4 );
    close(fd);

    // print contents of second array to verify
    printf("\n"); // newline of demarcation
    
    for (int i=0 ; i<10 ; i++)
        printf("random %d: %d\n", i, verifyArray[i]);
    

    return 0;
}
