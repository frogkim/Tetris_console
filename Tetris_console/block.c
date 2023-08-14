#include "block.h"

static int color_arr[7] = {1, 2, 3, 4, 5, 6, 7};
// helper functions
static void set_block(dot_t dst[][BLOCK_SIZE], int src[][BLOCK_SIZE], int color);
static void rotate_block(int block[][BLOCK_SIZE]);

// define functions
void Init_block(void)
{
    //dot_t g_block_arr[BLOCK_TYPE][BLOCK_DIRECTION][BLOCK_SIZE][BLOCK_SIZE];

    int block_arr[BLOCK_TYPE][BLOCK_SIZE][BLOCK_SIZE] = {
       {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}}, // I block
       {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, // square block
       {{0, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}}, // T block
       {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, // L block
       {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, // reverse L block
       {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}}, // 2 block
       {{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}}  // reverse 2 block
    };

    for (int i = 0; i < BLOCK_TYPE; ++i) {
        //dot_t g_block_arr[BLOCK_TYPE][BLOCK_DIRECTION][BLOCK_SIZE][BLOCK_SIZE];
        set_block(g_block_arr[i][0], block_arr[i], color_arr[i]);
        
        rotate_block(block_arr[i]);
        set_block(g_block_arr[i][1], block_arr[i], color_arr[i]);
        
        rotate_block(block_arr[i]);
        set_block(g_block_arr[i][2], block_arr[i], color_arr[i]);
        
        rotate_block(block_arr[i]);
        set_block(g_block_arr[i][3], block_arr[i], color_arr[i]);
    }
} // end set block

void set_block(dot_t dst[][BLOCK_SIZE], int src[][BLOCK_SIZE], int color)
{
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            dst[i][j].fill = src[i][j];
            if (dst[i][j].fill > 0) {
                dst[i][j].color = color;
            } else {
                dst[i][j].color = 0;
            }
        } 
    }
}

void rotate_block(int block[][BLOCK_SIZE])
{
    int tmp = block[0][0];

    //left edge
    block[0][0] = block[1][0];
    block[1][0] = block[2][0];
    block[2][0] = block[3][0];

    //bottom
    block[3][0] = block[3][1];
    block[3][1] = block[3][2];
    block[3][2] = block[3][3];

    // right edge
    block[3][3] = block[2][3];
    block[2][3] = block[1][3];
    block[1][3] = block[0][3];

    // top
    block[0][3] = block[0][2];
    block[0][2] = block[0][1];
    block[0][1] = block[0][0];
    block[0][0] = tmp;

    // inside
    tmp = block[1][1];
    block[1][1] = block[2][1];
    block[2][1] = block[2][2];
    block[2][2] = block[1][2];
    block[1][2] = tmp;
}

void Appear_block(void)
{

}

void Move_block(key_t key)
{

}