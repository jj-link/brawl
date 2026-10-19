#pragma force_active on
extern "C" {
void* fn_123_470C(void* p, short n);
void __dl__FPv(void* p);
}

extern "C" void* fn_123_12D4C(void* p, short n) {
    if (p != 0) {
        fn_123_470C(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
