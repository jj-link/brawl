#include <types.h>
#pragma force_active on

class soRet {
public:
    u32 m_pad;
    s32 m_val;
};

class soInner {
public:
    virtual void f0();
    virtual soRet* f1();
    virtual void f2();
    virtual void f3();
};

class soOuter {
public:
    u32 m_pad[4];
    soInner m_obj;
};

extern "C" s32 fn_27_1C8ED8(soOuter* self) {
    return self->m_obj.f1()->m_val;
}
