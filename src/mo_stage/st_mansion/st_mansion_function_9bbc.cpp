#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>

#pragma force_active on

extern "C" {
extern const float lbl_47_rodata_A0[];

void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, unsigned long);
void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);
}

inline float clampRange(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" void fn_47_9BBC(unsigned char* self) {
    const float* k = &lbl_47_rodata_A0[0];
    unsigned char* cb = self + 0xd0;
    if (cb != 0) {
        unsigned char* model = **(unsigned char***)(self + 0x44);
        if (model != 0) {
            if (*(int*)(model + 0x11c) == 0) {
                *(int*)(cb + 0xc) = 0;
                *(void**)(model + 0x11c) = cb;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(unsigned short*)(model + 0x122) =
                    (unsigned short)*(unsigned int*)(self + 0xc4);
            }
            float scale;
            float value;
            if (self[0x16c] == 1) {
                value = k[2] - **(float**)(self + 0x164);
            } else {
                value = **(float**)(self + 0x164);
            }
            scale = *(float*)(self + 0x168);
            float* data = *(float**)(cb + 4);
            data[8] = scale;
            data[9] = scale * clampRange(value, k[3], k[2]);
            data[10] = scale;
            Vec3f pos;
            pos.m_x = k[1];
            pos.m_y = k[1];
            pos.m_z = k[1];
            setPos__14snd3DGeneratorFP5Vec3f((snd3DGenerator*)(self + 0x17c), &pos);
        }
    }
}
