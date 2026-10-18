#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_1E08(void* p, short flag) {
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
