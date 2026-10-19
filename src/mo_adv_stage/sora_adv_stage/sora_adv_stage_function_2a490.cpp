#pragma force_active on
extern "C" {
void fn_40_27868(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_40_2A490(void* p, int size) {
    if (p) {
        fn_40_27868(p, 0);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
