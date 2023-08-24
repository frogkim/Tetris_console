#include "header.h"
#include <time.h>

static unsigned long l_clock;
static struct _timespec64 l_timer; // from time.h

PTHREAD_START_ROUTINE clock_func(void)
{
    int count = 0;
    int count_old = 0;
    const unsigned long mili_second = 100000000;

    int return_code;
    while (!g_game_over) {
        if (g_escape) {
            break;
        }
        
        return_code = _timespec64_get(&l_timer, TIME_UTC);
        if (return_code < 0) {
            printf("Error to get time\n");
            return 0;
        }

        count = l_timer.tv_nsec / mili_second;
        if (count != count_old) {
            ++l_clock;
            count_old = count;
        } else {
            if (count_old >= 10) {
                count_old = 0;
            }
        }
    } // end while
    return 0;
}

unsigned long get_count(void)
{
    return l_clock;
}

time_t generate_rand(void)
{
    return time(get_count());
}
