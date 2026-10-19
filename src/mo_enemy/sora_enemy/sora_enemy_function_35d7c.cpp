#pragma force_active on
typedef unsigned char u8;
typedef short s16;

extern "C" void* fn_41_35D20(void* p, s16 flag);
extern "C" void* fn_41_33D4C(void* p, s16 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_35D7C(void* p, s16 flag) {
    if (p != 0) {
        fn_41_35D20((u8*)p + 0x8, -1);
        fn_41_33D4C(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
