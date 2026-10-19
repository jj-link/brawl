#pragma force_active on
extern "C" void fn_104_3C90(void* p, short flag);

extern "C" void* fn_104_155E0(void* p, short flag) {
    if (p != 0) {
        fn_104_3C90(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
