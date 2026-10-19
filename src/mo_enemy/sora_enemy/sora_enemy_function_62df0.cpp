#pragma force_active on
extern "C" void fn_41_62D24(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_62DF0(void* p, short flag) {
    if (p) {
        if (p) {
            fn_41_62D24(static_cast<char*>(p) + 4, static_cast<short>(-1));
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
