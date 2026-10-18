#include <types.h>
#pragma force_active on

struct IntArray {
    char filler[12];
    s32* m_ints;
};

extern "C" void fn_96_F5C0(IntArray* work, s32 value, u32 index) {
    work->m_ints[index] = value;
}
