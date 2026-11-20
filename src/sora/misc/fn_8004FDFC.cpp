#include <types.h>
#pragma force_active on

extern "C" {
void* fn_8004E588(void* ptr);
unsigned int* fn_8004E594(void* ptr);
extern void* g_GameGlobal;
extern int lbl_8042C0A0[];
extern int lbl_8042BF98[];
}

extern "C" s32 fn_8004FDFC(void) {
    u32 flag;
    s32 count = 0x7D;
    s32 i;
    s32 j;
    s32 k;
    int* entry;

    for (i = 0; i < 0x66; i++) {
        s32 bit = i * 2;
        u32* words = (u32*)fn_8004E588(g_GameGlobal);
        u32 mask = 1 << (bit % 32);
        u32 v = words[bit / 32] & mask;
        if ((u32)(v != 0) == 1) {
            count++;
        }
    }

    for (k = 0; k < 0x1F; k++) {
        entry = lbl_8042C0A0;
        flag = 1;
        s32 key = lbl_8042BF98[k * 2 + 1];
        for (j = 0; j < 12; entry++, j++) {
            if (key == *entry) {
                u32* words = (u32*)fn_8004E594(g_GameGlobal);
                u32 mask = 1 << (j % 32);
                u32 v = words[j / 32] & mask;
                flag = v != 0;
                break;
            }
        }
        if (flag == 1) {
            count++;
        }
    }

    return count;
}
