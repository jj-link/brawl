#include <types.h>
#pragma force_active on

struct Sub {
    virtual ~Sub();
    virtual void target(s32);

    u8 pad;
    u8 flag : 1;
    u8 state;

    bool enabled() const {
        return flag;
    }

    void invoke(s32 x) {
        if (enabled() == true && state == 0)
            target(x);
    }
};

struct Bits {
    s16 value;
};

extern "C" void fn_27_3860BC(void*, s16*, s32);

extern "C" void fn_27_386010(void* arg0, Bits arg1, s32 arg2) {
    Sub* obj = (Sub*)((u8*)arg0 + 12);

    if (arg1.value & 2) {
        if (obj->enabled() == true && obj->state == 0)
            obj->invoke(arg2);
    }

    s16 value = arg1.value;
    fn_27_3860BC((u8*)arg0 + 4, &value, arg2);
}
