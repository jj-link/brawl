#include <types.h>
#pragma force_active on

extern "C" {
    void* fn_27_1F1F58(s8* fighterId);
    void* fn_27_1F218C(s32 id);
    s32 fn_27_1F2D0C(s8* fighterId);

    u8 fn_27_21F164(s8* fighterId) {
        if (fn_27_1F2D0C(fighterId) != 0) {
            void* fs = fn_27_1F1F58(fighterId);
            return *(u8*)((u8*)fn_27_1F218C(*(s32*)((u8*)fs + 0xAC)) + 0x11);
        }
        return *(u8*)((u8*)fn_27_1F218C(0) + 0x11);
    }
}
