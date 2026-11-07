#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

struct Words12 { unsigned int v[12]; };

extern "C" void fn_52_128DC(char* self) {
    char* cb = self + 0xd0;
    if (cb != 0) {
        nw4r::g3d::ScnMdlSimple* model = *(nw4r::g3d::ScnMdlSimple**)(*(char**)(self + 0x44));
        if (model != 0) {
            if (model->m_calcWorldCallBack == 0) {
                *(int*)(cb + 0xc) = 0;
                *(int*)(*(char**)(cb + 4)) = *(int*)(self + 0xc4);
                model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)cb;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = (short)*(int*)(*(char**)(cb + 4));
            }
            char* dst = *(char**)(cb + 4);
            *(Words12*)(dst + 0x50) = *(Words12*)(self + 0x168);
        }
    }
}
