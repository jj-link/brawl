#pragma force_active on
extern "C" void* fn_41_57348(void* ptr, short flag);
extern "C" void* fn_41_57284(void* p, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_573A8(void* p, short flag) {
    if (p != 0) {
        fn_41_57348((char*)p + 0x128, -1);
        fn_41_57284(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
