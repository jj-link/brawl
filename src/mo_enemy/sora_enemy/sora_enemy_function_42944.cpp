#pragma force_active on
extern "C" void fn_41_428E4(void*, short);
extern "C" void fn_41_427E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_42944(char* p, short flag) {
    if (p) {
        fn_41_428E4(p + 0x68, -1);
        fn_41_427E4(p + 4, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
