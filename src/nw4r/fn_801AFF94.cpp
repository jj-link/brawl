#include <types.h>
#pragma force_active on

struct Inner {
    char pad[0x140];
    s32* m_array;
};

struct Outer {
    Inner* m_inner;
    s32 m_index;
    char pad8[4];
    s32 m_ret;
};

extern "C" s32 fn_801AFF94(Outer* arg0, s32 arg1) {
    Inner* inner = arg0->m_inner;
    if (inner != NULL && arg0->m_ret != 0) {
        if (arg1 != 0) {
            inner->m_array[arg0->m_index] |= 2;
        }
        return arg0->m_ret;
    }
    return 0;
}
