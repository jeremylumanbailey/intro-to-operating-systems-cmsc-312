
/*
 * shm-client - client program to demonstrate shared memory.
 * shm-client - not sure of the origin of these code segments.
 * possibly: David Marshalls course : http://www.cs.cf.ac.uk/Dave/C/CE.html
 * or Steve Holmes : http://www2.its.strath.ac.uk/courses/c/
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHMSZ     27

int
main()
{
    int shmid, shmid2;
    key_t key,key2;
    char *shm,*s, *sharedmem2, *shared2;

    /*
     * We need to get the segment named
     * "5678", created by the server.
     */
    key = 0511;



    key2 = 0622;

    /*
     * Locate the segment.
     */
    if( (shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0 )
    {
        perror("shmget");
        exit(1);
    }


    /*
     * Locate the second segment.
     */
    if( (shmid2 = shmget(key2, SHMSZ, IPC_CREAT | 0666)) < 0 )
    {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if( (shm = shmat(shmid, NULL, 0)) == (char *) -1 )
    {
        perror("shmat");
        exit(1);
    }


    /*
     * Now we attach the second segment to our data space.
     */
    if( (sharedmem2 = shmat(shmid2, NULL, 0)) == (char *) -1 )
    {
        perror("shmat");
        exit(1);
    }



/***************************************************************************/

    while( *shm != '1' )
        sleep(1);

        /*
     * Now read what the server put in the memory.
     */



        for( s = shm; *s != (char) NULL; s++ )
        putchar(*s);
    putchar('\n');


    shared2 = sharedmem2;
    // for( c = 'a'; c <= 'z'; c++ )
    //     *s++ = c; /* post fix */

    strcpy(shared2,"shared ");
   // *shared2 = 'shared ';
    //*shared2 = (char) NULL;


        for( shared2 = sharedmem2; *shared2 != (char) NULL; shared2++ )
        putchar(*shared2);
    putchar('\n');



        /*
     * Now read what the server put in the memory.
     */


    s = shm;
    // for( c = 'a'; c <= 'z'; c++ )
    //     *s++ = c; /* post fix */
    *s = '2';


    /*
     * Finally, change the first character of the
     * segment to '*', indicating we have read
     * the segment.
     */
   // *shm = '*';
   // *sharedmem2 = '*';

    return 0;
}
