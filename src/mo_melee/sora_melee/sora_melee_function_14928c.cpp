#include <types.h>
#pragma force_active on

typedef struct Entry {
    char *m_0;
    u32 m_4;
    u32 m_8;
} Entry;

extern Entry lbl_27_bss_3210[];

extern "C" void *fn_27_14928C(s32 p0, s32 p1)
{
    return *(void **)(lbl_27_bss_3210[p1].m_0 + 0xbc);
}
