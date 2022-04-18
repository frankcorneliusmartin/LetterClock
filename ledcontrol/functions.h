#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "LedControl.h"
// interface

/**
 * @brief create random matrix animation
 *
 * @param lc ledControl of the panel
 * @param n x-dimension of the grid
 * @param m y-dimension of the grid
 */
void the_matrix_animation(LedControl lc, int n, int m);
// int snake_length(bool column[8]);
int snake_encode(bool column[8]);

#endif