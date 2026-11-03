#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
void* fn_8004E5D8(void*, void*);
}

extern "C" s32 fn_800580AC(s32 arg0) {
    s32 result = 0;
    switch (arg0) {
    case 0x1B:
    case 0x18: {
        s32 count = 0;
        s32 i = 0;
        do {
            u16 v = *(u16*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0x9c);
            if ((v >> 5) & 7) {
                count++;
            }
            i++;
        } while (i < 0x23);
        switch (arg0) {
        case 0x1B:
            if (count >= 0x23) {
                result = 1;
            }
            break;
        case 0x18:
            if (count >= 0xA) {
                result = 1;
            }
            break;
        }
        break;
    }
    }
    return result;
}
