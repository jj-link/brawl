#pragma force_active on
extern "C" void* fn_119_11A58(void* p, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_11A98(void* p, short flag) {
    void* ret = p;
    if (p != 0) {
        fn_119_11A58(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return ret;
}
