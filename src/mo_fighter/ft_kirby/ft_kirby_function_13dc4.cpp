#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
}

extern "C" void* fn_96_13DC4(void* p, short n) {
    if (p && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
