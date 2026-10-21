#include <types.h>
#pragma force_active on

extern "C" {
    extern void* g_aiMgr;
    extern s8 lbl_27_data_47BF8;
    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void fn_27_1E87C0(void);
    void fn_27_2176C4(void* p);
    void fn_27_21C074(void* p);
    void fn_27_1E8EE4(void* p);
}

extern "C" void fn_27_1E8590(s32 flag) {
    if (g_aiMgr == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x388, 2);
        if (p != 0) {
            fn_27_1E87C0();
        }
    }
    if (g_aiMgr != 0) {
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
    lbl_27_data_47BF8 = -1;
}
