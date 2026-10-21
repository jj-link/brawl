#include <types.h>
#pragma force_active on

class ftManager;

extern "C" int getPlayerNo__9ftManagerFi(ftManager*, int);
extern "C" void fn_800E14A4(void*, int, int);
extern ftManager* g_ftManager;
extern char* g_IfAdvMngr;
extern char* g_IfMngr;

extern "C" void fn_27_2D7DBC(int, int entryId, int value) {
    int playerNo = getPlayerNo__9ftManagerFi(g_ftManager, entryId);
    if (g_IfAdvMngr != 0) {
        fn_800E14A4(*(void**)(g_IfAdvMngr + playerNo * 4 + 0xE8), value, 1);
    }
    char* m = g_IfMngr;
    if (m != 0) {
        u8 b = *(u8*)(m + playerNo + 0x68);
        fn_800E14A4(*(void**)(m + b * 4 + 0x4C), value, 1);
    }
}
