#include <types.h>
#include <nw4r/math.h>
#pragma force_active on

extern const float lbl_27_rodata_EC0;
extern "C" int randi__Fl(long);

struct Entry {
    int a;
    float b;
    int c;
    float d;
};

struct Self {
    int u0;
    float* arr;
    float u8;
    char pad[0x0F];
    signed char mode;
    short idx;
};

extern "C" void fn_27_C1B10(Self* self, float* p4, float* p5, float* p6, Entry* table, float f1, float f2)
{
    float f31 = f1;
    float f30 = f2;

    if (lbl_27_rodata_EC0 == f2) {
        if (self->mode >= 2) {
            f30 = *(float*)((char*)self->arr + 4);
        } else {
            f30 = self->arr[self->mode];
        }
    }

    if (*p5 == *p6) {
        if (lbl_27_rodata_EC0 == *p4) {
            if (randi__Fl(2) == 0) {
                f30 = f30;
            } else {
                f30 = -f30;
            }
            *p4 = f30;
        } else {
            if (*p4 < lbl_27_rodata_EC0) {
                f30 = f30;
            } else {
                f30 = -f30;
            }
            *p4 = f30;
        }
    } else if (*p5 > *p6) {
        *p4 = f30;
    } else {
        *p4 = -f30;
    }

    Entry* e = (Entry*)((char*)table + self->idx * 16);
    float d = (float)(double)nw4r::math::FAbs(*p6 - *p5);

    if (*p4 > lbl_27_rodata_EC0) {
        if (e->a == 0 || d < e->b) {
            if (lbl_27_rodata_EC0 == f31) {
                e->a = 2;
            } else if (f31 > lbl_27_rodata_EC0) {
                e->a = 3;
            } else {
                e->a = 1;
            }
            e->b = d;
        }
    } else if (e->c == 0 || d < e->d) {
        if (lbl_27_rodata_EC0 == f31) {
            e->c = 2;
        } else if (f31 > lbl_27_rodata_EC0) {
            e->c = 3;
        } else {
            e->c = 1;
        }
        e->d = d;
    }

    unsigned int flag = (e->a != 0 && e->c != 0);
    if (flag == 1) {
        self->u8 = lbl_27_rodata_EC0;
        return;
    }
    self->u8 = *p4;
}
