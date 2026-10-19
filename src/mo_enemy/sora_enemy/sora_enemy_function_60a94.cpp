#pragma force_active on
extern "C" void fn_41_609C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_60A94(void* p, short flag) {
    if (p) {
        if (p) {
            fn_41_609C8(static_cast<char*>(p) + 4, -1);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
