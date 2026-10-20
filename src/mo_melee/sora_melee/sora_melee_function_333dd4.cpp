#pragma force_active on
extern "C" {
void fn_27_3335CC(void* p, int x);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_333DD4(void* p, int flag) {
    if (p) {
        fn_27_3335CC(static_cast<char*>(p) + 0x8, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
