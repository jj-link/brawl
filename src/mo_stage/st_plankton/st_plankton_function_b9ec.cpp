#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

extern "C" const float lbl_74_rodata_160[];
extern "C" const float lbl_74_rodata_170[];

inline void setPosition(float* dst, float x, float y, float z) {
    dst[2] = x;
    dst[3] = y;
    dst[4] = z;
}

extern "C" void fn_74_B9EC(unsigned char* self) {
    unsigned char* base = self + 0xd0;
    if (base != 0) {
        nw4r::g3d::ScnMdlSimple* model = **(nw4r::g3d::ScnMdlSimple***)(self + 0x44);
        if (model != 0) {
            if (model->m_calcWorldCallBack == 0) {
                *(unsigned int*)(base + 0xc) = 0;
                model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)base;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = (short)**(unsigned int**)(base + 4);
            }
            float* src = *(float**)(self + 0x170);
            setPosition((float*)*(unsigned char**)(base + 4), src[0], src[1], lbl_74_rodata_160[0]);
            *(float*)(*(unsigned char**)(base + 4) + 0x1c) = (*(float**)(self + 0x170))[6];
            if (self[0x158] == 1) {
                *(float*)(*(unsigned char**)(base + 4) + 0x18) = lbl_74_rodata_170[0];
            } else {
                *(float*)(*(unsigned char**)(base + 4) + 0x18) = lbl_74_rodata_160[0];
            }
        }
    }
}
