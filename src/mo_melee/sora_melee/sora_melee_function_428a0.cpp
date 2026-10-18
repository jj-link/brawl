#include <types.h>
#pragma force_active on

class soIface {
public:
    virtual void f0();
    virtual s32* get(s32 idx);
};

struct soSrc {
    u32 m_0;
    s16 m_4;
};

extern "C" {
s32 fn_27_428A0(soSrc* src, soIface* obj, s32 n) {
    return *obj->get(src->m_4 + n);
}
}
