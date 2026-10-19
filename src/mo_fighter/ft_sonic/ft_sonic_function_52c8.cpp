#pragma force_active on
extern "C" {

void fn_27_1A3F58(void* ptr, short n);
void __dl__FPv(void* ptr);

void* fn_123_52C8(void* ptr, short n) {
    void* p = ptr;
    if (p != 0) {
        short m = -1;
        fn_27_1A3F58(p, m);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

} // extern "C"
