#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" {
void* fn_102_1BDA8(void* p, short n);
}

extern "C" void* fn_102_1BDA8(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
