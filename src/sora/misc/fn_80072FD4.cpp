#pragma force_active on
extern "C" void fn_801CA7E8(void*);

extern "C" void* fn_80072FD4(void* p, int flag) {
    if (p) {
        fn_801CA7E8(p);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
