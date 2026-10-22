#include <types.h>
#pragma force_active on

class ftManager;

extern "C" {
int getPlayerNo__9ftManagerFi(ftManager*, int);
void fn_800E14A4(void*, int, int);
void fn_800E3684(void*, int);
float fn_27_27D2C0(void*, float);
}

extern ftManager* g_ftManager;
extern char* g_IfAdvMngr;
extern char* g_IfMngr;

extern "C" void fn_27_2D7C44(char* self, int entryId, int value, int flag, int extra, float f) {
    int playerNo = getPlayerNo__9ftManagerFi(g_ftManager, entryId);
    char* arr = *(char**)(self + 0x2C);
    if (arr != 0) {
        *(int*)(arr + playerNo * 4 + 0xD0) = value;
    }
    *(s16*)(*(char**)(self + 0xC) + playerNo * 0x5C + 0xBA) = (s16)value;
    if (g_IfAdvMngr != 0) {
        fn_800E14A4(*(void**)(g_IfAdvMngr + playerNo * 4 + 0xE8), value, extra);
    }
    char* m = g_IfMngr;
    if (m != 0) {
        u8 b = *(u8*)(m + playerNo + 0x68);
        fn_800E14A4(*(void**)(m + b * 4 + 0x4C), value, extra);
    }
    if (flag != 0) {
        if (g_IfAdvMngr != 0) {
            float r = fn_27_27D2C0(self, f);
            char* p = *(char**)(g_IfAdvMngr + playerNo * 4 + 0xE8);
            if (*(u32*)(p + 0x1C) == *(u32*)(p + 0x18)) {
                *(float*)(p + 0x264) = r;
                fn_800E3684(p, 1);
            }
        }
        if (g_IfMngr != 0) {
            float r2 = fn_27_27D2C0(self, f);
            char* q = *(char**)(g_IfMngr + *(u8*)(g_IfMngr + playerNo + 0x68) * 4 + 0x4C);
            if (*(u32*)(q + 0x1C) == *(u32*)(q + 0x18)) {
                *(float*)(q + 0x264) = r2;
                fn_800E3684(q, 1);
            }
        }
    }
}
