#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

extern "C" void fn_8006E7E0(void* p);
extern "C" void __register_global_object(void* obj, void* dtor, void* reg);
extern "C" void fn_8006E7F0(void);
extern "C" u8 lbl_80497ED8[0x28];
extern "C" int lbl_805A01C8;
extern "C" u8 lbl_805A01CC;

extern "C" void fn_8007261C(void) {
    if ((s8)lbl_805A01CC == 0) {
        fn_8006E7E0(&lbl_805A01C8);
        __register_global_object(&lbl_805A01C8, (void*)fn_8006E7F0, lbl_80497ED8);
        lbl_805A01CC = 1;
    }
}

__declspec(section ".ctors") extern void* const fn_8007261C_ctor = (void*)fn_8007261C;
