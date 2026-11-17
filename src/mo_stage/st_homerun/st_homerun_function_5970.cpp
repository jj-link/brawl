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
    char pad1[0x7];
    Vec3f *arr;
    char pad2[0xC];
    float *p168;
    char pad3[0x4];
    float *p170;
    float *p174;
    char pad4[0x8];
    u8 idx;
} FnObj;

extern "C" {
void fn_88_5970(FnObj *self)
{
    int off;
    if ((int)self->state != 2) {
        return;
    }
    if (*self->p174 > 0.0f) {
        for (int j = 0; j < 12; j += 6) {
            off = (u8)j * 12;
            *(float *)((char *)self->arr + off) -= *self->p170;
            *(float *)((char *)self->arr + off + 12) -= *self->p170;
            *(float *)((char *)self->arr + off + 24) -= *self->p170;
            *(float *)((char *)self->arr + off + 36) -= *self->p170;
            *(float *)((char *)self->arr + off + 48) -= *self->p170;
            *(float *)((char *)self->arr + off + 60) -= *self->p170;
        }
    }
    for (;;) {
        bool lt = self->arr[self->idx].x < *self->p168 - 625.0f;
        if (!lt) {
            return;
        }
        int prev = self->idx + 11;
        if (prev >= 12) {
            prev -= 12;
        }
        self->arr[self->idx].x = 250.0f + self->arr[prev].x;
        self->idx++;
        if (self->idx >= 12) {
            self->idx -= 12;
        }
    }
}
}
