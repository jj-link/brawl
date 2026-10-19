#pragma force_active on
extern "C" void fn_27_7700(void*, short);
extern "C" void* fn_41_212C(void* ptr, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_28D0(char* p, short flag) {
    if (p != 0) {
        if (p + 0x14 != 0) {
            fn_27_7700(p + 0x14, 0);
        }
        fn_41_212C(p + 0x8, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
