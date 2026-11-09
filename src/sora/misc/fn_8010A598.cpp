#include <types.h>
#include <gf/gf_pad_status.h>
#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#pragma force_active on
class Obj {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual void fn6();
    virtual void fn7();
    virtual void fn8();
    virtual void fn9();
    virtual void fn10();
    virtual void fn11(void*, void*);
    virtual void fn12();
    virtual void fn13(void*);
};
extern "C" int fn_800BA3D8(void*);
extern float lbl_805A2850;
extern float lbl_805A2854;
extern "C" void fn_8010A598(void* self, int arg1) {
    gfPadStatus status;
    void* entry = (char*)self + 8;
    int i = 2;
    for (; i < 7; ++i) {
        Obj* obj = *(Obj**)((char*)self + 0x110);
        obj->fn13(*(void**)((char*)(*(void**)((char*)entry + 0xE8)) + 0x10));
        entry = (char*)entry + 4;
    }
    if (arg1 != 0) {
        g_gfPadSystem->getSysPadStatus(fn_800BA3D8((char*)self + 0x20), &status);
        int index;
        switch (status.m_controllerType) {
        case 0: index = 2; break;
        case 1: index = 3; break;
        case 3: index = 4; break;
        case 2: index = 5; break;
        default: index = 6; break;
        }
        Obj* obj = *(Obj**)((char*)self + 0x110);
        entry = *(void**)((char*)self + index * 4 + 0xE8);
        obj->fn11(*(void**)((char*)obj + 0xE4), *(void**)((char*)entry + 0x10));
        int a = 0;
        if (*(int*)((char*)self + 0x118) == 0 &&
            *(unsigned int*)((char*)self + 0x11C) >= 1)
            a = 1;
        if (a != 0) goto visible;
        {
            int b = 0;
            if (*(int*)((char*)self + 0x120) == 0 &&
                *(unsigned int*)((char*)self + 0x124) >= 1)
                b = 1;
            if (b == 0) goto hidden;
        }
    visible:
        ((MuObject*)entry)->setFrameVisible(lbl_805A2850);
        return;
    hidden:
        ((MuObject*)entry)->setFrameVisible(lbl_805A2854);
    }
}