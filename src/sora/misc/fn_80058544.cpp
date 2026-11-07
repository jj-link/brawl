#include <types.h>
#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
void* fn_8004E5D8(void*, void*);
}
extern "C" s32 fn_80058544(s32 arg0) {
    s32 result = 0;
    switch (arg0) {
    case 0x26:
        result = 1;
        for (s32 i = 0; i < 0x23; i++) {
            if (*(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0xac) == 0) {
                result = 0;
                break;
            }
        }
        break;
    case 0xd:
        for (s32 i = 0; i < 0x23; i++) {
            if (*(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0xac) >= 0x2328U) {
                result = 1;
                break;
            }
        }
        break;
    case 0xc:
        for (s32 i = 0; i < 0x23; i++) {
            if (*(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0xac) >= 0x2ee0U) {
                result = 1;
                break;
            }
        }
        break;
    case 0x69:
        for (s32 i = 0; i < 0x23; i++) {
            if (*(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0xac) >= 0x3a98U) {
                result = 1;
                break;
            }
        }
        break;
    case 0x57: {
        u32 sum = 0;
        s32 i = 0;
        do {
            sum += *(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0xac);
            i++;
        } while (i < 0x23);
        if (sum >= 0x493e0U) result = 1;
        break;
    }
    case 0x7b: {
        u32 sum = 0;
        s32 i = 0;
        do {
            sum += *(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0xac);
            i++;
        } while (i < 0x23);
        if (sum >= 0x5b8d8U) result = 1;
        break;
    }
    case 0x7c: {
        u32 sum = 0;
        s32 i = 0;
        do {
            sum += *(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0xac);
            i++;
        } while (i < 0x23);
        if (sum >= 0x6ddd0U) result = 1;
        break;
    }
    case 0x4b: {
        u32 sum = 0;
        s32 i = 0;
        do {
            sum += *(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0xac);
            i++;
        } while (i < 0x23);
        if (sum >= 0x249f0U) result = 1;
        break;
    }
    case 0x5d: {
        u32 sum = 0;
        s32 i = 0;
        do {
            sum += *(u32*)((char*)fn_8004E5D8(g_GameGlobal, (void*)i) + 0xac);
            i++;
        } while (i < 0x23);
        if (sum >= 0x3a980U) result = 1;
        break;
    }
    }
    return result;
}