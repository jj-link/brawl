#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

extern "C" void fn_79_AB94(unsigned char* self) {
    unsigned char* p = self + 0xd0;
    if (p != 0) {
        nw4r::g3d::ScnMdlSimple* m = **(nw4r::g3d::ScnMdlSimple***)(self + 0x44);
        if (m != 0) {
            if (m->m_calcWorldCallBack == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                m->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)p;
                m->EnableScnMdlCallbackTiming(1);
                m->m_nodeIndex = (short)**(unsigned int**)(p + 4);
            }
            float* src = *(float**)(self + 0x160);
            if (src != 0) {
                float* dst = (float*)(*(unsigned char**)(p + 4) + 8);
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
        }
    }
}
