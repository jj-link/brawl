#include <types.h>
#pragma force_active on

struct Entry {
    u32 m_0;
    u32 m_4;
    u32 m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
    bool fn_27_145694(int p1) {
        return lbl_27_bss_3210[p1].m_0 != 0;
    }
}
