#include <types.h>
#pragma force_active on

struct soRet {
    s32 a;
    s32 b;
};

class soSub {
public:
    virtual void v0();
    virtual soRet* get();
};

class soOuter {
public:
    u8 pad[0x10];
    soSub m_sub;
};

extern "C" {
s32 fn_27_FD298(soOuter* self) {
    return self->m_sub.get()->b;
}
}
