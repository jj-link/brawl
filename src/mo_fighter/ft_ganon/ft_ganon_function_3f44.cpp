#pragma force_active on
extern "C" {
void* fn_27_A1E80(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_109_3F44(void* p, short flags) {
    if (p != 0) {
        fn_27_A1E80(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
