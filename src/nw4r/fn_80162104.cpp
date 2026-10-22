#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

extern "C" void fn_8015C528(void* output);
extern "C" void fn_8015C890(void* output);
extern "C" void __register_global_object(void* obj, void* dtor, void* reg);
extern "C" void fn_8015C538(void);
extern "C" void fn_8015C8A0(void);
extern "C" u8 lbl_8049EDB0[0xC];
extern "C" u8 lbl_8049EDBC[0x10];
extern "C" int lbl_805A04B0;
extern "C" int lbl_805A04B4;
extern "C" u8 lbl_805A04B8;
extern "C" u8 lbl_805A04B9;

extern "C" void fn_80162104(void) {
    if ((s8)lbl_805A04B8 == 0) {
        fn_8015C528(&lbl_805A04B0);
        __register_global_object(&lbl_805A04B0, (void*)fn_8015C538, lbl_8049EDB0);
        lbl_805A04B8 = 1;
    }
    if ((s8)lbl_805A04B9 == 0) {
        fn_8015C890(&lbl_805A04B4);
        __register_global_object(&lbl_805A04B4, (void*)fn_8015C8A0, lbl_8049EDBC);
        lbl_805A04B9 = 1;
    }
}

__declspec(section ".ctors") extern void* const fn_80162104_ctor = (void*)fn_80162104;
