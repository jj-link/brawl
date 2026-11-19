#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>

#pragma force_active on

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, u32);
extern const float lbl_62_rodata_178[];
}

extern "C" void fn_62_E1EC(u8* self) {
    const float* k = lbl_62_rodata_178;
    u8* cb = self + 0xd0;
    if (cb != 0) {
        u8* model = **(u8***)(self + 0x44);
        if (model != 0) {
            if (*(u32*)(model + 0x11c) == 0) {
                *(u32*)(cb + 0xc) = 0;
                **(u32**)(cb + 4) = *(u32*)(self + 0xc4);
                *(u8**)(model + 0x11c) = cb;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(u16*)(model + 0x122) = (u16)**(u32**)(cb + 4);
            }
            Matrix* mtx = *(Matrix**)(self + 0x158);
            if (mtx != 0) {
                switch (*(u8*)(self + 0x150)) {
                case 0x13: {
                    float t = *(float*)(self + 0x184) + k[1];
                    *(float*)(self + 0x184) = t;
                    if (t > k[2]) {
                        *(float*)(self + 0x184) = k[2];
                    }
                    *(float*)(self + 0x164) = *(float*)(self + 0x164) - *(float*)(self + 0x184);
                    if (k[0] != *(float*)(self + 0x174)) {
                        *(float*)(self + 0x174) = *(float*)(self + 0x174) * k[3];
                    }
                    break;
                }
                default: {
                    float x2 = mtx->m[2][3];
                    float x1 = mtx->m[1][3];
                    float x0 = mtx->m[0][3];
                    *(float*)(self + 0x160) = x0;
                    *(float*)(self + 0x164) = x1;
                    *(float*)(self + 0x168) = x2;
                    mtx->getRotate((Vec3f*)(self + 0x16c));
                    float s;
                    float v0 = *(float*)(self + 0x16c);
                    s = k[4];
                    float v1 = *(float*)(self + 0x170);
                    float r0 = s * v0;
                    float v2 = *(float*)(self + 0x174);
                    float r1 = s * v1;
                    float r2 = s * v2;
                    *(float*)(self + 0x16c) = r0;
                    *(float*)(self + 0x170) = r1;
                    *(float*)(self + 0x174) = r2;
                    break;
                }
                }
                *(float*)(self + 0x168) = k[0];
                u8* d = *(u8**)(cb + 4);
                *(float*)(d + 0x8) = *(float*)(self + 0x160);
                *(float*)(d + 0xc) = *(float*)(self + 0x164);
                *(float*)(d + 0x10) = *(float*)(self + 0x168);
                d = *(u8**)(cb + 4);
                *(float*)(d + 0x14) = *(float*)(self + 0x16c);
                *(float*)(d + 0x18) = *(float*)(self + 0x170);
                *(float*)(d + 0x1c) = *(float*)(self + 0x174);
                ((snd3DGenerator*)(self + 0x1a4))->setPos((Vec3f*)(self + 0x160));
            }
        }
    }
}