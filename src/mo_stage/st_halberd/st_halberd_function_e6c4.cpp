#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

struct Words12 { unsigned int v[12]; };

extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator* self, Vec3f* pos);

extern "C" void fn_57_E6C4(char* self) {
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
            char* src = *(char**)(self + 0x160);
            if (src != 0) {
                char* dst = *(char**)(cb + 4);
                *(Words12*)(dst + 0x50) = *(Words12*)src;
                src = *(char**)(self + 0x160);
                float a = *(float*)(src + 0x2c);
                float b = *(float*)(src + 0x1c);
                float c = *(float*)(src + 0xc);
                Vec3f pos;
                pos.m_x = c;
                pos.m_y = b;
                pos.m_z = a;
                setPos__14snd3DGeneratorFP5Vec3f((snd3DGenerator*)(self + 0x1a8), &pos);
            }
        }
    }
}
