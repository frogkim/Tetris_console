#include "header.h"

#define THREADS 3
HANDLE h_thread[THREADS];
DWORD ThreadID[THREADS];

int main(void)
{
    g_game_over = FALSE;
    g_escape = FALSE;
    g_level = 0;

    Init_block();
    Init_Draw();
    Init_frame();

    h_mutex_key = CreateMutex(NULL, FALSE, TEXT("Mutex_Key"));
    h_thread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)key_collect_func, (LPVOID)NULL, 0, &ThreadID[0]);
    h_thread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)run_func, (LPVOID)NULL, 0, &ThreadID[1]);
    h_thread[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)clock_func, (LPVOID)NULL, 0, &ThreadID[2]);
    WaitForMultipleObjects(THREADS, h_thread, TRUE, INFINITE);

    return 0;
}

