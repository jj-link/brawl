#include <math.h>
#pragma force_active on

#pragma fp_contract on

extern float lbl_805A3CD0;
extern float lbl_805A3CD4;
extern float lbl_805A3CD8;
extern float lbl_805A3CDC;
extern float lbl_805A3CE0;
extern float lbl_805A3CE4;

float fn_802820A4(float x, float y) {
    float ax = (float)fabs(x);
    float ay = (float)fabs(y);
    float t;
    float r;

    if (ax <= ay) {
        t = ax / (ay + lbl_805A3CD0);
        r = t * (lbl_805A3CD4 * t) + t;
        r = t * (t * (lbl_805A3CD8 * t)) + r;
    } else {
        float s;

        t = ay / (ax + lbl_805A3CD0);
        s = t * (lbl_805A3CD4 * t) + t;
        s += (t * (lbl_805A3CD8 * t)) * t;
        r = lbl_805A3CDC - s;
    }

    if (y < lbl_805A3CE4) {
        r = lbl_805A3CE0 - r;
    }
    if (x < lbl_805A3CE4) {
        r = -r;
    }

    return r;
}
