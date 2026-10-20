#include <types.h>
#pragma force_active on

class SubBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

extern "C" void fn_27_1A98D4(void* self) {
    SubBase* sub = (SubBase*)((char*)self + 0xc);
    sub->v4();
}
