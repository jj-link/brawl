#pragma force_active on
extern "C" void* fn_41_5D258(void*, short);
extern "C" void* fn_41_33D4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5D2BC(void* p, short flag) {
    if (p != 0) {
        fn_41_5D258(static_cast<char*>(p) + 8, -1);
        fn_41_33D4C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
