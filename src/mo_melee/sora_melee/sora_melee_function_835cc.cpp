#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;

struct Obj {
    u32 a;
    s32 b;
    u16 c;
    s16 d;
};

extern "C" {
extern u8 lbl_27_bss_11A8;
extern Obj lbl_27_bss_11AC;
extern char lbl_27_bss_E6C;
extern void fn_27_842D8(void*, s32);
extern void* __register_global_object(void*, void*, void*);

Obj* fn_27_835CC() {
    if ((signed char)lbl_27_bss_11A8 == 0) {
        lbl_27_bss_11AC.b = -1;
        lbl_27_bss_11AC.c = 0;
        lbl_27_bss_11AC.d = -1;
        __register_global_object(&lbl_27_bss_11AC, (void*)fn_27_842D8, &lbl_27_bss_E6C);
        lbl_27_bss_11A8 = 1;
    }
    return &lbl_27_bss_11AC;
}
}
