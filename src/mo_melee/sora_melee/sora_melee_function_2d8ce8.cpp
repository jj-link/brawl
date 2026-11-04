#include <types.h>
#pragma force_active on
class ftManager;
extern ftManager* g_ftManager;
extern "C" void* g_IfMngr;
extern "C" void* g_IfAdvMngr;
extern "C" int fn_27_10AAC4(ftManager*, int);
extern "C" int fn_27_27D2AC(void*, int);
extern "C" void fn_800E1ED8(void*, int, int);
extern "C" void fn_27_2D8CE8(void* self, int id, int index, int unused, int kind) {
    switch (fn_27_10AAC4(g_ftManager, id)) {
    case 29: case 31: case 33:
        switch (kind) {
        case 29: kind = 29; break;
        case 31: kind = 33; break;
        case 30: kind = 31; break;
        }
        break;
    case 3: case 4:
        switch (kind) {
        case 3: kind = 3; break;
        case 24: kind = 4; break;
        }
        break;
    case 14: case 15:
        switch (kind) {
        case 13: kind = 14; break;
        case 14: kind = 15; break;
        }
        break;
    case 12: case 44:
        switch (kind) {
        case 11: kind = 12; break;
        case 48: kind = 44; break;
        }
        break;
    case 23: case 45:
        switch (kind) {
        case 21: kind = 23; break;
        case 49: kind = 45; break;
        }
        break;
    default: return;
    }
    if (g_IfMngr) {
        int n = fn_27_27D2AC(self, index);
        u8* mgr = (u8*)g_IfMngr;
        fn_800E1ED8(*(void**)(mgr + 0x4c + (mgr + n)[0x68] * 4), 0, kind);
    }
    if (g_IfAdvMngr) {
        int n = fn_27_27D2AC(self, index);
        u8* mgr = (u8*)g_IfAdvMngr;
        fn_800E1ED8(*(void**)(mgr + 0xe8 + n * 4), 0, kind);
    }
}