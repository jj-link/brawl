#pragma force_active on
extern "C" {
void fn_62_2CE8(void* p, int flags);
void __dl__FPv(void* p);
}

extern "C" void* fn_62_3208(void* p, int flags) {
    if (p) {
        fn_62_2CE8(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
