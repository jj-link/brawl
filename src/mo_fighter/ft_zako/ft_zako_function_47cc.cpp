#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_126_4828(void* ptr, short flag);

extern "C" void* fn_126_47CC(void* a, short b) {
    if (a != 0) {
        fn_126_4828(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
