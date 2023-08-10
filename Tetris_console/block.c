#include "header.h"

// helper functions
static int* get_block(int type);
static void rotate_block(void);
static void move_block(key_t key);

// define functions
void Init_block(void)
{

}

void DeInit_block(void)
{

}


int* get_block_or_null(int type) 
{
    ;
    switch (type) {
    case 0:
        int** ret = { {0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 1, 0} };
        return ret;
    default:
        break;
    }
    return NULL;
}


dot_t block[BLOCK_TYPE][BLOCK_DIRECTION][BLOCK_SIZE][BLOCK_SIZE] = {
    { {0, 0}, {0, 0}, {1, 0}, {0, 0} },
    { {0, 0}, {0, 0}, {1, 0}, {0, 0} },
    { {0, 0}, {0, 0}, {1, 0}, {0, 0} },
    { {0, 0}, {0, 0}, {1, 0}, {0, 0} }
};

dot_t block_2[BLOCK_DIRECTION][BLOCK_SIZE][BLOCK_SIZE] = {
    { {0, 0}, {0, 0}, {0, 0}, {0, 0} },
    { {0, 0}, {1, 1}, {1, 1}, {0, 0} },
    { {0, 0}, {1, 1}, {1, 1}, {0, 0} },
    { {0, 0}, {0, 0}, {0, 0}, {0, 0} }
};


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