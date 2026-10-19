#pragma force_active on
extern "C" void* fn_41_29E4(void* self, short flag);
extern "C" void fn_41_1569C(void* p, short n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_1ADA0(void* p, short flag) {
    if (p != 0) {
        fn_41_29E4((char*)p + 0xC8, -1);
        fn_41_1569C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
