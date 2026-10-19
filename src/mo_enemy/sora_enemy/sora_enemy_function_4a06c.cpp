#pragma force_active on
extern "C" void fn_41_49FA0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4A06C(void* p, short flag) {
    if (p != 0) {
        if (p != 0) {
            fn_41_49FA0((char*)p + 4, -1);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
