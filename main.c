//
// LOTO7
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int compare (const void *a, const void *b);


int
main (int argc, char **argv)
{
    int ret;
    int i;
    int buf[7];

    // init
    memset (buf, 0, sizeof (buf));

    // rand seed
    srand ((unsigned int) time (NULL));

    // choice the numbers
    int overlap;        // 重複した数
    int counter = 0;    // 配列に格納された数
    while (counter < 7)
    {
        overlap = 0;
        ret = rand () % 37 + 1;
        for (i = 0; i <= counter; i++)
        {
            if (ret == buf[i])
            {
                overlap++;
            }
        }

        if (overlap == 0)
        {
            buf[counter] = ret;
            counter++;
        }
    }

    // sort
    qsort (buf, 7, sizeof (int), compare);

    // display
    printf ("======= LOTO7 =======\n");
    for (i = 0; i < 7; i++)
    {
        printf ("%2d ", buf[i]);
    }
    printf ("\n");

    return 0;
}


int
compare (const void *a, const void *b)
{
    return ((int) *(int *)a) - ((int) *(int *)b);
}

