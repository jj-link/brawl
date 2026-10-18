#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
}

extern "C" void* fn_96_4340(void* p, short flag) {
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
