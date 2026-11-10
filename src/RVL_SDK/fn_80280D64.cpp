#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(s32 x);
};

extern Object_vptr_0* lbl_805A0EB8;
extern "C" void __dl__FPv(void*);

extern "C" s32* fn_80280D64(s32* arg0, s32 arg1) {
    if (arg0 != 0) {
        lbl_805A0EB8->slot3(*arg0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}