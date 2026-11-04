#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
extern u8 lbl_805A25D0;

void fn_800F218C(char* self) {
    char* out = self;
    u8* lp = &lbl_805A25D0;
    int i;
    for (i = 0; i < 2; i++) {
        if (i == 0 && ((u8*)g_GameGlobal->m_appData)[0x10] == 0) {
            *(s32*)(out + 0x74) = 5;
            *(s32*)(out + 0x78) = 0;
        } else {
            char* r9 = *(char**)(self + 0xAC) + (*lp) * 0x14;
            switch (*(s32*)(r9 + 0x35c)) {
            case 0:
            case 1:
                if (*(s32*)(r9 + 0x35c) == 1 && ((u8*)r9)[0x359] == 0) {
                    *(s32*)(out + 0x74) = 4;
                    *(s32*)(out + 0x78) = 0;
                    break;
                }
                *(s32*)(out + 0x74) = 1;
                *(s32*)(out + 0x78) = *(s32*)(r9 + 0x364);
                break;
            case 2:
                *(s32*)(out + 0x74) = 2;
                *(s32*)(out + 0x78) = 0;
                break;
            case 3:
                *(s32*)(out + 0x74) = 3;
                *(s32*)(out + 0x78) = 0;
                break;
            }
        }
        out += 8;
        lp++;
    }
}
}
