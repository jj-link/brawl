#include <types.h>
#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void* fn_8004E5D8(void*, void*);
int fn_80055888(int, int);
}
extern "C" s32 fn_80059890(s32 arg0) {
    s32 fourth;
    s32 third;
    s32 second;
    s32 first;
    s32 last;
    s32 result = 0;
    switch (arg0) {
    case 0x4B:
        for (first = 0; first < 0x23; first++) {
            u16 v = *(u16*)((char*)fn_8004E5D8(g_GameGlobal, (void*)first) + 0x9c);
            if ((v >> 8) & 7) { result = 1; break; }
        }
        break;
    case 0x4C:
        result = 1;
        for (second = 0; second < 0x23; second++) {
            u16 v = *(u16*)((char*)fn_8004E5D8(g_GameGlobal, (void*)second) + 0x9c);
            if (!((v >> 8) & 7)) { result = 0; break; }
        }
        break;
    case 0x59:
        for (third = 0; third < 0x23; third++) {
            u16 v = *(u16*)((char*)fn_8004E5D8(g_GameGlobal, (void*)third) + 0x9c);
            if (((u32)(v >> 8) & 7) >= 5) { result = 1; break; }
        }
        break;
    case 0x4F:
        result = 1;
        for (fourth = 0; fourth < 0x23; fourth++) {
            u16 v = *(u16*)((char*)fn_8004E5D8(g_GameGlobal, (void*)fourth) + 0x9c);
            if (!((v >> 5) & 7)) { result = 0; break; }
        }
        break;
    case 0x51:
        result = 1;
        for (fourth = 0; fourth < 0x23; fourth++) {
            u16 v = *(u16*)((char*)fn_8004E5D8(g_GameGlobal, (void*)fourth) + 0x9c);
            if (!((v >> 2) & 7)) { result = 0; break; }
        }
        break;
    case 0x54: case 0x55: case 0x56: case 0x57: case 0x58:
        result = 1;
        for (last = 0; last < 0x23; last++) {
            u32 v = *(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)last) + 0xcc + (arg0 - 0x54) * 4);
            if (((v >> 30) & 1) != 1) { result = 0; break; }
        }
        break;
    case 0x5E:
        if (fn_80055888(1, 0) >= 20) result = 1;
        break;
    case 0x5F:
        if (fn_80055888(1, 0) >= 41) result = 1;
        break;
    case 0x60:
        if (fn_80055888(2, 0) >= 10) result = 1;
        break;
    case 0x61:
        if (fn_80055888(2, 0) >= 21) result = 1;
        break;
    }
    return result;
}