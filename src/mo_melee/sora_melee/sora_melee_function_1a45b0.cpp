#include <types.h>
#pragma force_active on

struct Foo {
    s32 m_00;
    s32 m_04;
    s32 m_08;
};

extern "C" s32 fn_27_1A45B0(Foo* p) {
    return p->m_08 >> 22;
}
