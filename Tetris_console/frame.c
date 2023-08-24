#include "header.h"


// helper functions
void helper_finish_key_collect(void);

// define functions
void Init_frame(void)
{
    // EMPTY
    // NOT DECIDE YET
}

PTHREAD_START_ROUTINE run_func(void)
{
    unsigned long count = 0;
    unsigned long count_old = 0;

    int velocity;
    while (!g_game_over) {
        if (g_escape) {
            break;
        }

        if (g_level >= 10) {
            return -1;
        }

        if (g_key.max != KEY_NOTHING) {
            Move_block(g_key.max);
            g_key.max = KEY_NOTHING;
        }

        velocity = 10 - g_level;
        count = get_count() % velocity;
        if(count != count_old) {
            count_old = count;
            if (count_old == 0) {
                Move_block(KEY_DOWN);
                g_key.max = KEY_NOTHING;
            }
        }

        Draw();
    } // while end
    if (g_game_over) {
        printf("Game Over\n");
        printf("Press Enter\n");
        getchar();
    }

    return 0;
}
