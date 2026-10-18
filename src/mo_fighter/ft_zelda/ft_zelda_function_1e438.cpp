#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
}

extern "C" void* fn_104_1E438(void* p, short size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
