#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual u32 get() = 0;
};

extern "C" s32 fn_801B4374(Obj* arg0, Obj* arg1) {
    u32 t = arg1->get();
    u32 s = arg0->get();
    if (s == t) {
        if (*(u32*)((char*)arg1 + 0x18) == *(u32*)((char*)arg0 + 0x18)) {
            return 1;
        }
    }
    return 0;
}
