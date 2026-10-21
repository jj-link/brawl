#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern u8 lbl_8059E7D8[8];
extern "C" u32 getLanguage__10GameGlobalFv(GameGlobal* self);

extern "C" u8 fn_8014E1EC(void) {
    u32 lang = getLanguage__10GameGlobalFv(g_GameGlobal);
    if (lang >= 7) {
        lang = 0;
    }
    u32 val = lbl_8059E7D8[lang];
    if (val == 0x11) {
        return 1;
    }
    return (u8)val;
}
