#include <mu/mu_object.h>
#pragma force_active on
extern "C" const float lbl_10_rodata_5C0[];
extern "C" void fn_10_169F0(void* self, int arg) {
    const float* base = lbl_10_rodata_5C0;
    float a, b;
    switch (arg) {
    case 0:
        a = base[58];
        b = a;
        break;
    case 1:
        a = base[58];
        b = base[62];
        break;
    case 2:
        a = base[93];
        b = base[58];
        break;
    }
    MuObject* obj = *(MuObject**)((char*)self + 0xb0);
    obj->setFrameNode(a);
    obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(b);
    obj->setFrameVisible(a);
    obj->m_modelAnim->m_anmObjVisRes->SetUpdateRate(b);
}