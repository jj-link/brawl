#include <types.h>
#pragma force_active on

class soModuleAccesser {
public:
    void activate();
};

struct Pad8 {
    s32 a;
    s32 b;
};

class IfaceObj : public Pad8 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
};

extern "C" void fn_27_12B488(void* self) {
    u8* base = (u8*)self;
    soModuleAccesser* acc = *(soModuleAccesser**)(base + 0x60);
    acc->activate();

    IfaceObj* obj = *(IfaceObj**)(*(u8**)(*(u8**)(base + 0x60) + 0xd8) + 0x9c);
    obj->s5();

    IfaceObj* obj2 = *(IfaceObj**)(*(u8**)(*(u8**)(base + 0x60) + 0xd8) + 0x4);
    obj2->s9();
}
