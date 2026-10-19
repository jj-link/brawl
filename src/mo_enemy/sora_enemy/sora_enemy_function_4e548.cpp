#pragma force_active on
extern "C" void* fn_41_4E4E8(void* ptr, short flag);
extern "C" void fn_41_4E424(void* p, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4E548(void* p, short flag) {
    if (p != 0) {
        fn_41_4E4E8((char*)p + 0x38, (short)-1);
        fn_41_4E424(p, (short)0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
