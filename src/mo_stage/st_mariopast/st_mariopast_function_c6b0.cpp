#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on
extern "C" void fn_48_C6B0(unsigned char* self) {
    unsigned char* p = self + 0xD0;
    if (p != 0) {
        nw4r::g3d::ScnMdlSimple* model = *(nw4r::g3d::ScnMdlSimple**)*(unsigned char**)(self + 0x44);
        if (model != 0) {
            if (model->m_calcWorldCallBack == 0) {
                *(unsigned int*)(p + 0xC) = 0;
                model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)p;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = (short)**(unsigned int**)(p + 4);
            }
            if (*(int*)(self + 0x158) != 0) {
                unsigned char* q = *(unsigned char**)(p + 4);
                *(float*)(q + 0x8) = *(float*)(self + 0x164);
                *(float*)(q + 0xC) = *(float*)(self + 0x168);
                *(float*)(q + 0x10) = *(float*)(self + 0x16C);
            }
        }
    }
}