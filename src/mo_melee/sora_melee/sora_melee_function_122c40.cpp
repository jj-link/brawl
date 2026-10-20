#include <types.h>
#pragma force_active on

struct Foo {
    u32 m_0;
    u32 m_4;
    union {
        struct {
            u32 _lo : 18;
            u32 _f : 1;
            u32 _hi : 13;
        };
        u32 m_8;
    };
};

extern "C" {
u32 fn_27_122C40(const Foo *obj)
{
    return obj->_f;
}
}
