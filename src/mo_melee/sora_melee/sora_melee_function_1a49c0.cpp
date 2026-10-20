#include <types.h>
#pragma force_active on

namespace {
struct Flags {
    s32 m_0;
    s32 m_4;
    s32 m_8;
};
}

extern "C" s32 fn_27_1A49C0(Flags* arg) {
    return arg->m_8 >> 28;
}
