#pragma force_active on
#include <mt/mt_vector.h>

struct Self {
    char pad[0xC8];
    unsigned char flag;
    char pad2[0x164 - 0xC9];
    Vec3f* points;
    char pad3[0x174 - 0x168];
    unsigned char idx;
    char pad4[0x188 - 0x175];
    Vec3f out;
};

extern "C" void fn_81_4814(Self*);
extern float lbl_81_rodata_100;

extern "C" void fn_81_7A38(Self* self) {
    fn_81_4814(self);
    if (self->flag && self->points) {
        if (lbl_81_rodata_100 == self->out.m_x) {
            Vec3f d;
            Vec3fSub(&d, self->points + (self->idx * 2 + 1),
                     self->points + self->idx * 2);
            self->out = d;
        }
    }
}
