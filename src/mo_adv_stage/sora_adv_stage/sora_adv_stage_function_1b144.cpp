#include <gr/gr_gimmick.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern const float lbl_40_rodata_280;
extern const float lbl_40_rodata_2C8;

extern "C" void fn_40_1B144(grGimmick* self) {
    unsigned char* p = (unsigned char*)self;
    if (p[0x16C]) {
        Vec3f rot;
        rot = self->getRot();
        rot.m_z += *(float*)(p + 0x168);
        self->setRot(&rot);
        unsigned char* data = *(unsigned char**)(p + 0x150);
        if (!data[0xCA] &&
            ((float)(double)nw4r::math::FAbs(rot.m_z - *(float*)(data + 0x3C)) < *(float*)(p + 0x1B4) ||
             (float)(double)nw4r::math::FAbs(rot.m_z - *(float*)(data + 0x38)) < *(float*)(p + 0x1B4))) {
            *(float*)(p + 0x168) = -*(float*)(p + 0x168);
        }
        if (rot.m_z > lbl_40_rodata_2C8) {
            rot.m_z -= lbl_40_rodata_2C8;
            self->setRot(&rot);
        }
        if (rot.m_z < lbl_40_rodata_280) {
            rot.m_z += lbl_40_rodata_2C8;
            self->setRot(&rot);
        }
    }
}
