#include <types.h>

extern char lbl_80529CF8[];
extern void fn_80239A24(s32);

#pragma force_active on

void fn_8023EDBC(u32 arg0, s16 arg1) {
    char* base = (char*)lbl_80529CF8;
    s32 var_r3 = 0;
    char* it;
    s32 i;
    int x;

    *(unsigned short*)(base + 0x18F6) = (unsigned short)arg1;

    for (x = 0; x < 3; x++) {
        switch (*(u16*)(base + 0x185C + x * 0x34)) {
        case 2: case 3: case 4: case 5: case 6:
            var_r3++;
            break;
        }
    }

    if ((u32)(u8)var_r3 <= 1) {
        fn_80239A24(0);
    }

    it = (char*)lbl_80529CF8 + 0x1854;
    for (i = 0; i < 3; i++, it += 0x34) {
        unsigned short v = *(unsigned short*)(it + 8);
        if (v != 0 && v != 1 && *(unsigned short*)(it + 0xA) == arg0) {
            *(unsigned short*)(it + 8) = 0;
            *(unsigned short*)(it + 0xA) = 0xFFFF;
            *(unsigned char*)(it + 0xD) = 0;
            *(u32*)(it + 0x10) = 0;
            ((void (*)(u16))*(void**)(it + 4))((u16)i);
            return;
        }
    }
}
