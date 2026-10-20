#include <revolution/OS/OSError.h>
#pragma force_active on

extern "C" const char lbl_27_data_5ADA8[];
extern "C" char* lbl_27_bss_5668;
extern "C" char* g_ftManager;
extern "C" void* fn_27_10AAEC(void* mgr, void* param);

extern "C" void fn_27_27E864(void* a, void* b, void* c) {
    OSReport(lbl_27_data_5ADA8, c, c);
    if (lbl_27_bss_5668 != 0) {
        void* r = fn_27_10AAEC(g_ftManager, b);
        char* p = lbl_27_bss_5668;
        p[0x270] = 1;
        *(void**)(p + 0x268) = r;
        *(void**)(p + 0x26c) = c;
    }
}
