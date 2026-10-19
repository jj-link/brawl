#pragma force_active on
extern "C" {
void fn_47_9A74(void* p, int n);
void __dl__FPv(void* p);
}

extern "C" void* fn_47_A1B4(void* p, int flag) {
    if (p != 0) {
        fn_47_9A74(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
