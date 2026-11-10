#include <types.h>
#pragma force_active on

extern "C" void __dl__FPv(void*);

struct Object_vptr_4_base { char pad[0x4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0(int);
};

struct Wrapper {
    char pad0[0xC];
    Object_vptr_4* objectC;
    Object_vptr_4* object10;
};

extern "C" void* fn_27_124010(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        Wrapper* w = (Wrapper*)arg0;
        void* r3 = w->objectC;
        if (r3 != 0) {
            if (r3 != 0) {
                ((Object_vptr_4*)r3)->slot0(1);
            }
            w->objectC = 0;
        }
        void* r3b = w->object10;
        if (r3b != 0) {
            if (r3b != 0) {
                ((Object_vptr_4*)r3b)->slot0(1);
            }
            w->object10 = 0;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
