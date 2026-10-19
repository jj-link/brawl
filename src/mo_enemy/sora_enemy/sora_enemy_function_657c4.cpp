#pragma force_active on
extern "C" void fn_41_656F8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_657C4(void* p, short flag) {
    if (p) {
        if (p) {
            fn_41_656F8(static_cast<char*>(p) + 4, -1);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
