#include "header.h"
// define blocks
static int block_arr[BLOCK_TYPE][BLOCK_SIZE][BLOCK_SIZE] = {
                                                            // I block
                                                           {{0, 0, 1, 0},
                                                            {0, 0, 1, 0},
                                                            {0, 0, 1, 0},
                                                            {0, 0, 1, 0}},
                                                            // square block
                                                           {{0, 0, 0, 0},
                                                            {0, 1, 1, 0},
                                                            {0, 1, 1, 0},
                                                            {0, 0, 0, 0}},
                                                            // T block
                                                           {{0, 0, 0, 0},
                                                            {0, 1, 1, 1},
                                                            {0, 0, 1, 0},
                                                            {0, 0, 0, 0}},
                                                            // L block
                                                           {{0, 1, 0, 0},
                                                            {0, 1, 0, 0},
                                                            {0, 1, 1, 0},
                                                            {0, 0, 0, 0}},
                                                            // reverse L block
                                                           {{0, 0, 1, 0},
                                                            {0, 0, 1, 0},
                                                            {0, 1, 1, 0},
                                                            {0, 0, 0, 0}},
                                                            // 2 block
                                                           {{0, 0, 0, 0},
                                                            {0, 1, 1, 0},
                                                            {0, 0, 1, 1},
                                                            {0, 0, 0, 0}},
                                                            // reverse 2 block
                                                           {{0, 0, 0, 0},
                                                            {0, 0, 1, 1},
                                                            {0, 1, 1, 0},
                                                            {0, 0, 0, 0}}
};

// helper functions
static int** get_block_or_null(int type);
static void rotate_block(dot_t** block);
static void move_block(key_t key);

// define functions
void Init_block(void)
{

}

void DeInit_block(void)
{

}


int** get_block_or_null(int type) 
{
    if (type == 0) {
        int** ret;
        return ret;
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


void rotate_block(dot_t** block)
{
    dot_t tmp[4];
    memcpy(tmp, &block[0][0], sizeof(dot_t) * 4);

    //left edge to top
    memcpy(&block[0][2], &block[1][0], sizeof(dot_t));
    memcpy(&block[0][1], &block[2][0], sizeof(dot_t));
    memcpy(&block[0][0], &block[3][0], sizeof(dot_t));

    //bottom to left edge
    memcpy(&block[1][0], &block[3][1], sizeof(dot_t));
    memcpy(&block[2][0], &block[3][2], sizeof(dot_t));
    memcpy(&block[3][0], &block[3][3], sizeof(dot_t));

    // right edge to bottom
    memcpy(&block[3][1], &block[2][3], sizeof(dot_t));
    memcpy(&block[3][2], &block[1][3], sizeof(dot_t));
    memcpy(&block[3][3], &block[0][3], sizeof(dot_t));

    // top to right edge
    memcpy(&block[3][3], &tmp[3], sizeof(dot_t));
    memcpy(&block[2][3], &tmp[2], sizeof(dot_t));
    memcpy(&block[1][3], &tmp[1], sizeof(dot_t));
    memcpy(&block[0][3], &tmp[0], sizeof(dot_t));

    // inside
    memcpy(&tmp[0],      &block[1][1], sizeof(dot_t));
    memcpy(&block[1][1], &block[2][1], sizeof(dot_t));
    memcpy(&block[2][1], &block[2][2], sizeof(dot_t));
    memcpy(&block[2][2], &block[1][2], sizeof(dot_t));
    memcpy(&block[1][2], &tmp[0], sizeof(dot_t));
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