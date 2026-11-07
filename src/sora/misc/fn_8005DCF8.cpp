#include <types.h>
#include <math.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

struct Input {
    u8 pad[5];
    u8 mode;
    u8 pad2[10];
    float time;
    float period;
    GXColor color;
    GXColor other;
};

extern "C" void fn_8005E438(int, GXColor*);

extern "C" void fn_8005DCF8(int arg0, Input* arg1) {
    switch (arg1->mode) {
    case 0: {
        float alpha;
        if (arg1->color.a == 0)
            alpha = 1.0f;
        else
            alpha = (float)arg1->color.a / 255.0f;
        float t = arg1->time;
        float s = (float)sin((6.2831854820251465f / arg1->period) * t - 1.5707963705062866f);
        GXColor color;
        color.r = arg1->color.r;
        color.g = arg1->color.g;
        color.b = arg1->color.b;
        color.a = (u8)(int)(alpha * (128.0f + 127.0f * s));
        GXColor copy = color;
        fn_8005E438(arg0, &copy);
        break;
    }
    case 2: {
        GXColor color = arg1->other;
        fn_8005E438(arg0, &color);
        break;
    }
    }
}