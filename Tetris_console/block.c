#include "header.h"

void set_block(void)
{

}

void rotate_block(void)
{
    dot_t tmp[4];
    memcpy(tmp, &g_block[0][0], sizeof(dot_t) * 4);

    //left edge to top
    memcpy(&g_block[0][2], &g_block[1][0], sizeof(dot_t));
    memcpy(&g_block[0][1], &g_block[2][0], sizeof(dot_t));
    memcpy(&g_block[0][0], &g_block[3][0], sizeof(dot_t));

    //bottom to left edge
    memcpy(g_block[1][0], &g_block[3][1],sizeof(dot_t));
    memcpy(g_block[2][0], &g_block[3][2],sizeof(dot_t));
    memcpy(g_block[3][0], &g_block[3][3],sizeof(dot_t));

    // right edge to bottom
    memcpy(g_block[3][1], &g_block[2][3], sizeof(dot_t));
    memcpy(g_block[3][2], &g_block[1][3], sizeof(dot_t));
    memcpy(g_block[3][3], &g_block[0][3], sizeof(dot_t));

    // top to right edge
    memcpy(g_block[3][3], &tmp[3], sizeof(dot_t));
    memcpy(g_block[2][3], &tmp[2], sizeof(dot_t));
    memcpy(g_block[1][3], &tmp[1], sizeof(dot_t));
    memcpy(g_block[0][3], &tmp[0], sizeof(dot_t));

    // inside
    memcpy(&tmp[0],       &g_block[1][1], sizeof(dot_t));
    memcpy(g_block[1][1], &g_block[2][1], sizeof(dot_t));
    memcpy(g_block[2][1], &g_block[2][2], sizeof(dot_t));
    memcpy(g_block[2][2], &g_block[1][2], sizeof(dot_t));
    memcpy(g_block[1][2], &tmp[0], sizeof(dot_t));
}

void move_block(key_t key)
{

}

void decide_frame(void)
{
    key_t key = get_key();
    if (key == KEY_UP) {

    } else {
        move_block(key);
    }
    
}

void calculate_diff(void)
{

}