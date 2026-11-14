#include <revolution/OS/OSMutex.h>
#include <types.h>
#pragma force_active on
extern float lbl_805A3630;
struct Unknown {
    int f0, f4, f8, fc, f10, f14, f18, f1c, f20;
    s16 f24, f26;
    f32 f28;
    u8 f2c, f2d;
    s32 f30;
    f32 f34, f38, f3c, f40, f44;
    OSMutex mutex_48;
};
extern "C" void *fn_801CAB04(void *arg0) {
    Unknown *self = (Unknown *)arg0;
    int t4 = (int)((char*)self + 4);
    int t10 = (int)((char*)self + 0x10);
    int t1c = (int)((char*)self + 0x1c);
    self->f4 = 0;
    self->f8 = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1c = 0;
    self->f20 = 0;
    self->f0 = 0;
    *(int*)t4 = t4;
    *((int*)t4 + 1) = t4;
    self->fc = 0;
    *(int*)t10 = t10;
    *((int*)t10 + 1) = t10;
    self->f18 = 0;
    *(int*)t1c = t1c;
    *((int*)t1c + 1) = t1c;
    self->f24 = 1;
    self->f26 = 1;
    self->f2d = 0;
    OSInitMutex(&self->mutex_48);
    float k = lbl_805A3630;
    self->f30 = 1;
    self->f28 = k;
    self->f2c = 0;
    self->f34 = k;
    self->f38 = k;
    self->f3c = k;
    self->f40 = k;
    self->f44 = k;
    return self;
}