#include <ai/ai_mgr.h>

#pragma force_active on

extern "C" int fn_27_1F2BE4() {
    switch (*(u32*)((char*)g_aiMgr + 0x370)) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 9:
    case 12:
    case 13:
    case 14:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 28:
    case 30:
    case 33:
    case 36:
    case 43:
    case 46:
    case 50:
        return 1;
    default:
        return 0;
    }
}
