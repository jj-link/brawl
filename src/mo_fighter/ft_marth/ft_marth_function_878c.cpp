#include <types.h>
#pragma force_active on

struct FtMarthVirtBase {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual u32 fn3();
};

extern "C" {
bool fn_106_878C(FtMarthVirtBase* obj) {
    return obj->fn3() == 0;
}
}
