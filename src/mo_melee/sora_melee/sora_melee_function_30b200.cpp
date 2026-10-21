#include <types.h>
#pragma force_active on

class IA {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual s32 f17(u32 id, void* obj) = 0;
};

class IB {
public:
    virtual void g0() = 0;
    virtual void g1() = 0;
    virtual void g2() = 0;
    virtual void g3() = 0;
    virtual void g4() = 0;
    virtual void g5() = 0;
    virtual void g6() = 0;
    virtual void g7() = 0;
    virtual void g8() = 0;
    virtual void g9() = 0;
    virtual void g10() = 0;
    virtual void g11() = 0;
    virtual void g12() = 0;
    virtual void g13() = 0;
    virtual void g14() = 0;
    virtual void g15(s32 a, void* p) = 0;
};

struct Msg {
    s32 id;
    u8 flag;
};

struct Mid {
    u8 pad0[0x54];
    IB* b;
    u8 pad1[0xc];
    IA* a;
};

struct Sub {
    u8 pad0[0xd8];
    Mid* mid;
};

extern "C" void fn_27_30B200(u8* obj) {
    Sub* sub = *(Sub**)(obj + 0x60);
    if (sub->mid->a->f17(0x12000003, sub) != 0) {
        Msg msg;
        msg.id = 0x837;
        msg.flag = 0;
        Mid* mid = *(Mid**)(*(u8**)(obj + 0x60) + 0xd8);
        mid->b->g15(3, &msg);
    }
}
