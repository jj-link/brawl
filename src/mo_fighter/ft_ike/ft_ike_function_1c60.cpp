#pragma force_active on
extern "C" {
void fn_119_1B44(void* p, short v);
void __dl__FPv(void* p);
}

extern "C" void* fn_119_1C60(void* p, short flag) {
    if (p != 0) {
        fn_119_1B44(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
