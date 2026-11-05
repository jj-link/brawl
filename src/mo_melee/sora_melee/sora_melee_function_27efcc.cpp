#include <ft/ft_manager.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_800DCE70(void*, void*);
extern "C" void fn_800DCE8C(void*, void*);
extern "C" int g_IfMngr;

extern "C" void fn_27_27EFCC(void* self, int entryId, int arg2, float f) {
    char* p = (char*)self;

    if (((*(unsigned char*)(p + 0x34) >> 7) & 1) == 0) return;
    if (*(int*)(p + 0x2c) == 0) return;
    if (g_ftManager->getPlayerNo(entryId) == 0) return;

    *(int*)(p + 0x40) = arg2;
    *(int*)(p + 0x44) = (int)f;

    if (g_IfMngr != 0) {
        fn_800DCE70((void*)g_IfMngr, (void*)arg2);
        fn_800DCE8C((void*)g_IfMngr, (void*)*(int*)(p + 0x44));
    }

    int val40 = *(int*)(p + 0x40);
    int val4c = *(int*)(p + 0x4c);
    if (val4c < val40) {
        int clamped = (val40 > 0xFFFF) ? 0xFFFF : val40;
        *(int*)(p + 0x4c) = clamped;
        *(short*)(*(int*)(p + 0x48) + 0xc8) = (short)clamped;
    }
}