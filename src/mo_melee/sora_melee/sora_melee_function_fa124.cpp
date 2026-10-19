#include <types.h>
#pragma force_active on

struct soResult {
    s32 a;
    s32 b;
};

class soInner {
public:
    virtual void f2();
    virtual soResult* get();
};

class soOuter {
public:
    u8 pad[0x10];
    soInner m_inner;
};

extern "C" s32 fn_27_FA124(soOuter* self) {
    return self->m_inner.get()->b;
}
