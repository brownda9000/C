// Copyright [year] <Copyright Owner>"  [legal/copyright]
// C code to illustrate using
// graphics in linux enviornment

#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_X 50
#define MAX_Y 30
#define DELAY 500000

int main() {
     int gd = DETECT, gm;
     initgraph(&gd, &gm, NULL);

     circle(MAX_X, MAX_X , MAX_Y);

     delay(DELAY);
     closegraph();
     return 0;
}

