#include <types.h>
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

class VirtObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9();
};

extern "C" void* fn_41_15FD4(void* p, int idx);
extern "C" void fn_41_1B0C0(void* p0, void* p1, int p2, float f1, int p3, int p4, int p5, int p6, bool p7, bool p8,
                            float f2, float f3, float f4, float f5);

extern "C" void fn_41_1627C(void* self, int idx, int a2, int a3, int a4, int a5, float farg0,
                            int a6, float farg1, float farg2) {
    if (idx != -1) {
        VirtObj* obj = *(VirtObj**)(*(char**)(*(char**)((char*)self + 0x20) + 0xd8) + 0xc);
        float f31 = obj->v9();
        float f30 = soValueAccesser::getValueFloat(*(soModuleAccesser**)((char*)self + 0x20), 0xbf0, 0);
        int sp8 = 0;
        fn_41_1B0C0(fn_41_15FD4(self, idx), *(void**)((char*)self + 0x20), a2, f31, a6, a3, a4, a5, sp8, sp8,
                    farg0, f30, farg1, farg2);
    }
}
