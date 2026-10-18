#pragma force_active on
typedef unsigned char u8;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct FnObj {
    char pad0[0x150];
    u8 state;
    char pad1[0x17];
    float *p168;
    char pad2[0x4];
    float *p170;
    float *p174;
    char pad3[0x8];
    u8 idx;
    char pad4[0x3];
    Vec3f arr[6];
} FnObj;

extern const float lbl_88_rodata_F8[4];

extern "C" {
void fn_88_5234(FnObj *self)
{
    const float *c = lbl_88_rodata_F8;
    if ((int)self->state != 2) {
        return;
    }
    if (*self->p174 > c[0]) {
        self->arr[0].x -= *self->p170;
        self->arr[1].x -= *self->p170;
        self->arr[2].x -= *self->p170;
        self->arr[3].x -= *self->p170;
        self->arr[4].x -= *self->p170;
        self->arr[5].x -= *self->p170;
    }
    {
        u8 i = self->idx;
        int prev;
        if (self->arr[i].x < *self->p168 - c[1]) {
            prev = i + 5;
            if (prev >= 6) {
                prev -= 6;
            }
            self->arr[i].x = c[2] + self->arr[prev].x;
            {
                u8 n = self->idx + 1;
                self->idx = n;
                if (n >= 6) {
                    self->idx = n - 6;
                }
            }
        }
    }
}
}
