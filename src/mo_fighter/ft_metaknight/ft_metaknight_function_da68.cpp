#include <types.h>
#pragma force_active on

struct Target {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8(int) = 0;
    virtual unsigned int v9(int) = 0;
};

extern "C" void fn_111_DA68(void* object) {
    u8* state = static_cast<u8*>(object);
    for (int i = 6; i < 0xC; ++i) {
        Target* t1 = *(Target**)(*(u8**)(state + 0xD8) + 0x54);
        if (t1->v9(i) == 1) {
            Target* t2 = *(Target**)(*(u8**)(state + 0xD8) + 0x54);
            t2->v8(i);
        }
    }
}
