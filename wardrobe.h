// wardrobe.h
#ifndef WARDROBE_H
#define WARDROBE_H

#include <stdio.h>
#include <string.h>

// Define a struct for wardrobe items
typedef struct {
    char hat[50];
    char accessories[100];
    char clothes[50];
    char shoes[50];
} Wardrobe;

// Function to display the wardrobe
void showWardrobe(Wardrobe w);

#endif // WARDROBE_H

