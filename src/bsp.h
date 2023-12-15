#pragma once
#include "pos.h"

typedef struct BSP_node {
    position pos;
    position scale;
    struct BSP_node *left;
    struct BSP_node *right;
} BSP_node;