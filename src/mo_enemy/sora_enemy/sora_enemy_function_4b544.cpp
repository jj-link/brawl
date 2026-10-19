#pragma force_active on
extern "C" void fn_41_4B7F4(void* self, short flag);
extern "C" void fn_41_4B4D8(void* self, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_4B544(void* p1, short p2) {
    if (p1 != 0) {
        short f = -1;
        fn_41_4B7F4(static_cast<char*>(p1) + 0xc8, f);
        fn_41_4B4D8(static_cast<char*>(p1) + 4, f);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
