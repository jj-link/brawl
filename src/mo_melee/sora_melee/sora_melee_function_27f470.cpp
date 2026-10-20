#pragma force_active on
extern "C" char* lbl_27_bss_5668;
extern "C" char* g_ftManager;
extern "C" void* fn_27_10AAEC(void* mgr);

extern "C" void fn_27_27F470(void* a, void* b, void* c) {
    if (lbl_27_bss_5668 != 0) {
        void* r = fn_27_10AAEC(g_ftManager);
        char* p = lbl_27_bss_5668;
        p[0x270] = 1;
        *(void**)(p + 0x268) = r;
        *(void**)(p + 0x26c) = c;
    }
}
