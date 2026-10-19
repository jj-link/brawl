#pragma force_active on
typedef signed short s16;

extern "C" {
void fn_126_8718(void* p, s16 flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_126_8790(void* p, s16 flag) {
    if (p != 0) {
        fn_126_8718(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
