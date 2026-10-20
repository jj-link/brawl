#pragma force_active on
typedef unsigned char u8;
typedef signed short s16;
typedef int s32;

extern "C" void fn_27_D35A4(void* p, s16 n);
extern "C" void fn_27_CB2FC(void* p, s16 n);
extern "C" void fn_41_2BF80(void* p, s16 n);

extern "C" void* fn_41_2C0AC(void* p, s16 n) {
    if (p != 0) {
        s16 m = -1;
        fn_27_D35A4((u8*)p + 0x264, m);
        fn_27_CB2FC((u8*)p + 0x28, m);
        s16 z = 0;
        fn_41_2BF80(p, z);
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
