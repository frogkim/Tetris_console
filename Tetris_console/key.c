#include "header.h"
static HANDLE h_in;

void helper_finish_key_collect(void);

PTHREAD_START_ROUTINE key_collect_func(void)
{
    h_in = GetStdHandle(STD_INPUT_HANDLE);

    INPUT_RECORD ir[KEY_BUF_SIZE];
    DWORD n_read;
    while (!g_game_over) {
        if (g_escape) {
            return 0;
        }
        ReadConsoleInput(h_in, ir, KEY_BUF_SIZE, &n_read); // NULL - ANSI mode
        for (DWORD i = 0; i < n_read; ++i) {
            if (!ir[i].Event.KeyEvent.bKeyDown) {
                continue;
            }

            switch (ir[i].Event.KeyEvent.wVirtualKeyCode) {
                case KEY_ESCAPE:
                    g_escape = TRUE;
                    goto out_of_loop;
                case KEY_LEFT:
                    ++g_key.left;
                    break;
                case KEY_UP:
                    ++g_key.up;
                    break;
                case KEY_RIGHT:
                    ++g_key.right;
                    break;
                case KEY_DOWN:
                    ++g_key.down;
                    break;
                case KEY_SPACE:
                    ++g_key.space;
                    break;
                default:
                    break;
            }
        }
    out_of_loop:
        FlushConsoleInputBuffer(h_in);
        if (!g_escape) {
            helper_finish_key_collect();
        }
    } // end while
    return 0;
}

void helper_finish_key_collect(void)
{
    unsigned int m = KEY_NOTHING;
    if (m < g_key.left) {
        m = g_key.left;
    }

    if (m < g_key.up) {
        m = g_key.up;
    }
    if (m < g_key.right) {
        m = g_key.right;
    }
    if (m < g_key.down) {
        m = g_key.down;
    }
    if (m < g_key.space) {
        m = g_key.space;
    }

    unsigned int tie_count = 0;
    if (m == g_key.left) {
        g_key.max = KEY_LEFT;
        ++tie_count;
    }
    if (m == g_key.up) {
        g_key.max = KEY_UP;
        ++tie_count;
    }
    if (m == g_key.right) {
        g_key.max = KEY_RIGHT;
        ++tie_count;
    }
    if (m == g_key.down) {
        g_key.max = KEY_DOWN;
        ++tie_count;
    }
    if (m == g_key.space) {
        g_key.max = KEY_SPACE;
        ++tie_count;
    }

    if (tie_count > 1) {
        g_key.max = KEY_NOTHING;
    }

    g_key.left = 0;
    g_key.up = 0;
    g_key.right = 0;
    g_key.down = 0;
    g_key.space = 0;
}
