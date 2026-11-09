#include <stdlib.h>

#pragma force_active on

extern "C" const float lbl_805A205C;
extern "C" const float lbl_805A20E4;

struct Obj {
    char pad[8];
    int state;
};

struct Input {
    char pad[4];
    unsigned int buttons;
    char pad2[0x28];
    signed char x, y;
    char pad3[10];
    int type;
};

struct Vec {
    float x, y;
};

extern "C" void fn_800A92C4(Obj* self, Input* input, Vec* out, int y) {
    int x;

    if (self->state == 2) {
        out->y = lbl_805A205C;
        out->x = lbl_805A205C;
        return;
    }

    switch (input->type) {
    case 0:
        {
            unsigned char a = input->y;
            unsigned char b = input->x;
            x = (signed char)b;
            y = (signed char)a;
        }
        break;
    case 1:
        {
            unsigned char a = input->y;
            unsigned char b = input->x;
            x = (signed char)b;
            y = (signed char)a;
        }
        break;
    case 2:
        {
            unsigned int buttons = input->buttons;
            if (!(buttons & 0x300)) {
                x = 0;
                y = 0;
                if (buttons & 2) x = 127;
                if (buttons & 1) x = -127;
                if (buttons & 4) y = -127;
                if (buttons & 8) y = 127;
            } else {
                x = 0;
                y = 0;
            }
        }
        break;
    case 3:
        {
            unsigned char a = input->y;
            unsigned char b = input->x;
            x = (signed char)b;
            y = (signed char)a;
        }
        break;
    default:
        x = (int)input;
        break;
    }

    int xx = (signed char)x;
    int sign = xx >> 31;
    int v = ((sign ^ xx) - sign) - 30;
    float f;
    if (v > 0) {
        f = (float)v / lbl_805A20E4;
        if ((signed char)x < 0) f = -f;
    } else {
        f = lbl_805A205C;
    }
    out->x = f;

    xx = (signed char)y;
    sign = xx >> 31;
    v = ((sign ^ xx) - sign) - 30;
    if (v > 0) {
        f = (float)v / lbl_805A20E4;
        if ((signed char)y < 0) f = -f;
    } else {
        f = lbl_805A205C;
    }
    out->y = f;
}
