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
    char pad1[0xB];
    Vec3f *arr;
    char pad5[0x8];
    float *p168;
    char pad2[0x4];
    float *p170;
    float *p174;
    char pad3[0x8];
    u8 idx;
} FnObj;

extern const float lbl_88_rodata_168[6];

extern "C" {
void fn_88_8328(FnObj *self)
{
    const float *c = lbl_88_rodata_168;
    if ((int)self->state != 2) {
        return;
    }
    if (*self->p174 > c[0]) {
        self->arr[self->idx].x -= *self->p170;
    }
    {
        u8 i = self->idx;
        if (self->arr[i].x < *self->p168 - c[5]) {
            float m = c[0];
            u8 best = 0;
            u8 j;
            for (j = 0; j < 12; j++) {
                if (self->arr[j].x > m) {
                    m = self->arr[j].x;
                    best = j;
                }
            }
            self->arr[i].x = c[4] + self->arr[best].x;
            if (self->idx == 0) {
                if (*self->p174 > c[0]) {
                    self->arr[self->idx].x -= *self->p170;
                }
            }
        }
    }
}
}