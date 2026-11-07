#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_27_711E4(void*, short, void*);
extern void fn_27_C93EC(void);
extern void fn_27_C940C(void);
extern void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern u8 lbl_27_data_3F058[0x70];
extern u8 lbl_27_data_3F148[0x90];

struct Foo {
    u8    head[0x24];
    void* f0;
    u8    f1;
    char  pad[3];
    void* f2;
    void* f3;
    void* f4;
    void* f5;
    u32   f6;
    u32   arr[24];
    u8    f7;
};

void* fn_27_1E16CC(Foo* o, short id) {
    fn_27_711E4(o, id, (void*)((u8*)o + 0x24));
    o->f1 = 0;
    o->f0 = &lbl_27_data_3F058;
    o->f2 = &lbl_27_data_3F058[0x34];
    o->f3 = &lbl_27_data_3F058[0x40];
    o->f4 = &lbl_27_data_3F148;
    o->f5 = &lbl_27_data_3F148[0x48];
    o->f6 &= 0x7FFFF;
    __construct_array(o->arr, (void (*)(void*))fn_27_C93EC, (void (*)(void*))fn_27_C940C, 16, 6);
    o->f7 = 0;
    return o;
}
}
