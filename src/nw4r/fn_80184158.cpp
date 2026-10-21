#include <types.h>
#pragma force_active on

extern "C" {

class IFace {
public:
    virtual s32 method0() = 0;
    virtual s32 method1() = 0;
    virtual s32 method2() = 0;
};

struct Obj {
    char pad[0x10];
    IFace* ptr;
};

s32 fn_80184158(Obj* obj) {
    IFace* p = obj->ptr;
    return p ? p->method2() : (s32)p;
}

}
