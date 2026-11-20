#pragma force_active on
class Vec3f;
#include <snd/snd_3d_generator.h>

extern "C" int fn_800797A4(snd3DGenerator*, int);
extern float lbl_27_data_547E0;
extern float lbl_40_rodata_1F8;

struct Sub {
    char pad0[0x16];
    unsigned short f16;
    char pad18[0x1A - 0x18];
    unsigned short f1A;
    char pad1C[0x22 - 0x1C];
    unsigned char f22;
};
struct Self {
    char pad0[0x0C];
    Sub* sub;
    snd3DGenerator gen;
    unsigned char state;
    char pad19[0x1C - 0x19];
    float timer;
    int handle;
    unsigned char flag;
};

extern "C" void fn_40_14D44(Self* self) {
    if (self->handle != -1 && self->state == 1) {
        if (self->flag == 0 && self->sub->f22 == 0) {
            if (self->handle != -1) {
                self->gen.stopSE(self->handle, self->sub->f1A);
                self->handle = -1;
            }
            float value = lbl_40_rodata_1F8;
            self->state = 0;
            self->timer = value;
            return;
        }
        if (self->sub->f16 != 0 && self->timer >= (float)self->sub->f16) {
            if (self->handle != -1) {
                self->gen.stopSE(self->handle, self->sub->f1A);
                self->handle = -1;
            }
            float value = lbl_40_rodata_1F8;
            self->state = 3;
            self->timer = value;
            return;
        }
        if (self->timer > lbl_40_rodata_1F8 && fn_800797A4(&self->gen, self->handle) == 0) {
            if (self->handle != -1) {
                self->gen.stopSE(self->handle, self->sub->f1A);
                self->handle = -1;
            }
            float value = lbl_40_rodata_1F8;
            self->state = 3;
            self->timer = value;
            return;
        }
    }
    float delta = lbl_27_data_547E0;
    self->timer += delta;
}
