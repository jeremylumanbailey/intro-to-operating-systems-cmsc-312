/*
 * The average procedure receives an array of real
 * numbers and returns the average of their
 * values. This toy service handles a maximum of
 * 200 numbers.
 * http://www.linuxjournal.com/article/2204?page=0,1
 */

const MAXAVGSIZE  = 200;

struct input_data
  {
  double input_data<200>; /* char input_data... */
  };


typedef struct input_data input_data;

program AVERAGEPROG {
    version AVERAGEVERS {
        string AVERAGE(string) = 1;
    } = 1;
} = 28855;
/* original: 22855  change to v00880079 28855*/
