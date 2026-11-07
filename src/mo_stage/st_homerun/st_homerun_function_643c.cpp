#include <nw4r/g3d/g3d_scnmdlsmpl.h>

#pragma force_active on

extern "C" const float lbl_88_rodata_118[];

struct Vec3 {
    float x, y, z;

    Vec3(float a, float b, float c) : x(c), y(b), z(a) {}
};

extern "C" void fn_88_643C(char* self) {
    const float* f = lbl_88_rodata_118;
    char* cb = self + 0xd0;

    if (cb != 0) {
        nw4r::g3d::ScnMdlSimple* model =
            *(nw4r::g3d::ScnMdlSimple**)(*(char**)(self + 0x44));

        if (model != 0) {
            if (model->m_calcWorldCallBack == 0) {
                *(int*)(cb + 0xc) = 0;
                *(int*)(*(char**)(cb + 4)) = *(int*)(self + 0xc4);
                model->m_calcWorldCallBack =
                    (nw4r::g3d::ICalcWorldCallBack*)cb;
                model->EnableScnMdlCallbackTiming(1);
                model->m_nodeIndex = (short)*(int*)(*(char**)(cb + 4));
            }

            char* dst = *(char**)(cb + 4);
            *(Vec3*)(dst + 8) = *(Vec3*)(self + 0x180);

            dst = *(char**)(cb + 4);
            Vec3 v(f[4], f[3], f[0]);
            *(Vec3*)(dst + 0x2c) = v;
        }
    }
}
