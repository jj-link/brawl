#include <types.h>
#pragma force_active on

extern "C" {
    extern void* g_aiMgr;
    extern s8 lbl_27_data_47BF8;
    void fn_27_2176C4(void* p);
    void fn_27_21C074(void* p);
    void fn_27_1E8EE4(void* p);
}

extern "C" void fn_27_1E8E70(s32 flag) {
    ((u8*)g_aiMgr)[0xa0] = (u8)flag;
    if (flag == 0) {
        lbl_27_data_47BF8 = -1;
        if (*(void**)((u8*)g_aiMgr + 0xfc) != 0) {
            fn_27_2176C4(*(void**)((u8*)g_aiMgr + 0xfc));
        }
        if (*(void**)((u8*)g_aiMgr + 0x100) != 0) {
            fn_27_21C074(*(void**)((u8*)g_aiMgr + 0x100));
        }
        fn_27_1E8EE4(g_aiMgr);
    }
}
