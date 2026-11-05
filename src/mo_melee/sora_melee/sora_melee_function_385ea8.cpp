#include <types.h>
#pragma force_active on

struct Sub {
    virtual ~Sub();
    virtual void target(s32);
    u8 pad;
    u8 flag : 1;
    u8 state;
    bool enabled() const { return flag; }
    void invoke(s32 x) {
        if (enabled() == true && state == 0)
            target(x);
    }
};

struct Bits {
    s16 value;
    Bits(const Bits& other) : value(other.value) {}
};

extern "C" void fn_27_385F54(void*, Bits, s32);

extern "C" void fn_27_385EA8(u8* self, const Bits& p, s32 v) {
    Sub* sub = (Sub*)(self + 0xC);
    if (p.value & 1) {
        if (sub->enabled() == true && sub->state == 0)
            sub->invoke(v);
    }
    Bits local(p);
    fn_27_385F54(self + 4, local, v);
}