#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

struct fnMid {
    u8 pad[0xc8];
    fnInner* inner;
};

struct fnTop {
    u8 pad[0x1a4];
    fnMid* mid;
};

extern "C" {
void fn_27_28FE44(fnTop* self) {
    self->mid->inner->v4();
}
}
