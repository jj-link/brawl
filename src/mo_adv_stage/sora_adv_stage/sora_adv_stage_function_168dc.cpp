#pragma force_active on
extern "C" void fn_40_15D24(void*);

extern "C" void fn_40_168DC(unsigned char* p) {
    if (p[6]) {
        fn_40_15D24(p);
    }
}
