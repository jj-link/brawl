#include <types.h>
#pragma force_active on

struct fn27Ret {
    u8 pad[6];
    s16 val;
};

class fn27Inner {
public:
    virtual void v0();
    virtual fn27Ret* get();
};

struct fn27Outer {
    u8 pad[0x58];
    fn27Inner* inner;
};

extern "C" {
s16 fn_27_44F80(fn27Outer* p) {
    return p->inner->get()->val;
}
}
