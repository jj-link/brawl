#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

struct MatrixWords { unsigned int v[12]; };

extern "C" void fn_66_F898(char* self) {
    char* cb = self + 0xd0;
    if (cb != 0) {
        nw4r::g3d::ScnMdlSimple* model = **(nw4r::g3d::ScnMdlSimple***)(self + 0x44);
        if (model != 0) {
            if (model->m_calcWorldCallBack == 0) {
                *(int*)(cb + 0xc) = 0;
                model->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)cb;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = **(unsigned int**)(cb + 4);
            }
            char* dst = *(char**)(cb + 4);
            *(MatrixWords*)(dst + 0x50) = *(MatrixWords*)(self + 0x158);
        }
    }
}