#include <types.h>
#pragma force_active on

struct soRet {
    int pad;
    s32 field;
};

class soInner {
public:
    virtual void v0();
    virtual soRet* v1();
    virtual void v2();
    virtual void v3();
};

struct soOuter {
    u8 pad[0x10];
    soInner inner;
};

extern "C" s32 fn_27_1CE7DC(soOuter* self) {
    return self->inner.v1()->field;
}
