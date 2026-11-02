#pragma force_active on

typedef unsigned char u8;
typedef int s32;

extern "C" {
extern u8 lbl_804DD0A4[0x3C];
extern u8 lbl_804DD098[0xC];
extern signed char lbl_805A0618;
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __register_global_object(void*, void (*)(void*), void*);
void fn_801E0704(void*);
void fn_801CFAB0(void*);
void fn_801CFB14(void*);
void fn_801CFB6C(void*);
}

extern "C" void* fn_801CFA14(void) {
    if (lbl_805A0618 == 0) {
        void* obj = &lbl_804DD0A4;
        __construct_array(obj, fn_801CFB6C, fn_801CFB14, 0xC, 3);
        ((s32*)obj)[9] = 0;
        ((u8*)obj)[0x28] = 0;
        fn_801E0704((u8*)obj + 0x2C);
        fn_801E0704((u8*)obj + 0x34);
        __register_global_object(obj, fn_801CFAB0, lbl_804DD098);
        lbl_805A0618 = 1;
    }
    return &lbl_804DD0A4;
}