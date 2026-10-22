#include <types.h>
#pragma force_active on

extern "C" {
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, void*);
extern void* g_gfPadSystem;
extern unsigned int lbl_8045D928[];
}

struct PadStatusLocal {
    char pad0[0xC];
    unsigned int buttons;
    char pad1[0x2C];
    unsigned int index;
};

extern "C" s32 fn_80110058(s32 arg0) {
    PadStatusLocal st;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (arg0 & (1 << i)) {
            getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, i, &st);
            if (st.buttons & lbl_8045D928[st.index]) {
                return 1;
            }
        }
    }
    return 0;
}
