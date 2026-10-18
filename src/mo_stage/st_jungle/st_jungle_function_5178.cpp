#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_51_5178(void* p, int count) {
    if (p != 0 && count > 0) {
        __dl__FPv(p);
    }
    return p;
}
