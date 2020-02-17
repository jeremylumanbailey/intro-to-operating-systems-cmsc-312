#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h> /* for exit */
#include <string.h>

#define SHMSZ     27


int
main()
{

    int shmid, shared_mem_id2;
    key_t key, second_key;
    char *shm,*s, *shared_mem_2, *shared_2;


    key = 0600;
    second_key = 0622;

    if( (shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0 )
    {
        perror("shmget");
        exit(1);
    }


        if( (shared_mem_id2 = shmget(second_key, SHMSZ, IPC_CREAT | 0666)) < 0 )
    {
        perror("shmget");
        exit(1);
    }


    if( (shm = shmat(shmid, NULL, 0)) == (char *) -1 )
    {
        perror("shmat");
        exit(1);
    }

    if( (shared_mem_2 = shmat(shared_mem_id2, NULL, 0)) == (char *) -1 )
    {
        perror("shmat");
        exit(1);
    }

    s = shm;
    *s = '1';
    pid_t pid, pid2;
    pid = fork();

    if (pid < 0) {
    fprintf(stderr, "Fork Failed");
    exit(-1);
    }
    else if (pid == 0) {


    int shmid, shared_mem_id2;
    key_t key,second_key;
    char *shm,*shared_mem_2, *s, *shared_2;

    key = 0600;
    second_key = 0622;

    if( (shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0 )
    {
        perror("shmget");
        exit(1);
    }

    if( (shared_mem_id2 = shmget(second_key, SHMSZ, IPC_CREAT | 0666)) < 0 )
    {
        perror("shmget");
        exit(1);
    }

    if( (shm = shmat(shmid, NULL, 0)) == (char *) -1 )
    {
        perror("shmat");
        exit(1);
    }

    if( (shared_mem_2 = shmat(shared_mem_id2, NULL, 0)) == (char *) -1 )
    {
        perror("shmat");
        exit(1);
    }

    while( *shm != '1' )
        sleep(1);

    for( s = shm; *s != (char) NULL; s++ )
        putchar(*s);
    putchar('\n');

    shared_2 = shared_mem_2;

    strcpy(shared_2,"shared ");

    for( shared_2 = shared_mem_2; *shared_2 != (char) NULL; shared_2++ )
        putchar(*shared_2);
    putchar('\n');

    s = shm;
    *s = '2';

    return 0;

    }

    else {
      wait (NULL);
    }

    pid2 = fork();
    if (pid2 < 0) {
    fprintf(stderr, "Fork Failed");
    exit(-1);
    }
    else if (pid2 == 0) {
      int shmid, shared_mem_id2;
      key_t key,second_key;
      char *shm,*shared_mem_2, *s, *shared_2;

      key = 0600;
      second_key = 0622;

      if( (shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0 )
      {
          perror("shmget");
          exit(1);
      }


      if( (shared_mem_id2 = shmget(second_key, SHMSZ, IPC_CREAT | 0666)) < 0 )
      {
          perror("shmget");
          exit(1);
      }

      if( (shm = shmat(shmid, NULL, 0)) == (char *) -1 )
      {
          perror("shmat");
          exit(1);
      }

      if( (shared_mem_2 = shmat(shared_mem_id2, NULL, 0)) == (char *) -1 )
      {
          perror("shmat");
          exit(1);
      }

      while( *shm != '2' )
          sleep(1);


      for( s = shm; *s != (char) NULL; s++ )
          putchar(*s);
      putchar('\n');

      shared_2 = shared_mem_2;
      strcat(shared_2,"memory");

      for( shared_2 = shared_mem_2; *shared_2 != (char) NULL; shared_2++ )
          putchar(*shared_2);
      putchar('\n');

      s = shm;
      *s = '3';

      return 0;
    }
    else {
      wait (NULL);
    }

    for( s = shm; *s != (char) NULL; s++ )
        putchar(*s);
    putchar('\n');


    for( shared_2 = shared_mem_2; *shared_2 != (char) NULL; shared_2++ )
      putchar(*shared_2);
    putchar('\n');

    while( *shm != '3' )
         sleep(1);

    printf("\nGoodBye\n");

    shmdt(s);
    shmdt(shared_2);
    shmctl(shmid, IPC_RMID, NULL);
    shmctl(shared_mem_id2, IPC_RMID,NULL);


    return 0;
}
