#include <stdio.h>

float gradient_w1(float w1, float w2, float x1, float x2, float y) {
    float c = y - (w1 * x1 + w2 * x2);
    return (c * -1 * x1);
}

float gradient_w2(float w1, float w2, float x1, float x2, float y) {
    float c = y - (w1 * x1 + w2 * x2);
    return (c * -1 * x2);
}

int main() {
    int data[4][3] = {
        {1, 0, 1},
        {2, 1, 9},
        {0, 1, 1},
        {-2, 1, 7}
    };
    
    float lambda = 0.05;
    
    float w1 = 0, w2 = 0;
    
    float prev_w1 = -1, prev_w2 = -1;
    
    while (w1 != prev_w1 || w2 != prev_w2) {
        for (int i = 0; i < 4; i++) {
            int x1 = data[i][0];
            int x2 = data[i][1];
            int y = data[i][2];
            w1 -= lambda * gradient_w1(w1, w2, x1, x2, y);
            w2 -= lambda * gradient_w2(w1, w2, x1, x2, y);
        }
        prev_w1 = w1;
        prev_w2 = w2;
    }
    printf("Calculated weights:\n");
    printf("w1: %.2f \nw2: %.2f", w1, w2);
    
    return 0;
}
