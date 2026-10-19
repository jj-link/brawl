#pragma force_active on
extern "C" void fn_41_5D18C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5D258(void* p, short flag) {
    if (p) {
        if (p) {
            fn_41_5D18C((char*)p + 4, -1);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
