#include <types.h>
#pragma force_active on

class fnObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v5(u32 a, void* b);
};

extern "C" void fn_27_28ED10(u8* self) {
    ((fnObj*)(self + 0x2c34))->v5(7, self + 0xcc);
}
