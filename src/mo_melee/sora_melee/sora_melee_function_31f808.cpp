#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_27_31F808(void* p, int size);
}

extern "C" void* fn_27_31F808(void* p, int size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
