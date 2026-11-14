#pragma force_active on
#include <types.h>

struct emCreate;
struct Sub { void* v0; void* v1; };

extern "C" {
void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_D0568(void*, int, int);
void fn_27_CA180(void*, int, int);
void fn_27_CB410(void*, int, int);
void __construct_array(void*, void*, void*, unsigned long, unsigned long);
void* __ct__18emTargetSearchUnitFv(void*);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_41_2A470(void*);
void* fn_41_2A480(void*, short);
void fn_41_49EAC(void*, void*);
extern char lbl_27_bss_A5C[], lbl_27_bss_69C[];
extern char lbl_41_data_FAE8[], lbl_41_data_FD34[], lbl_41_data_FEB0[];
extern char lbl_41_data_FF98[], lbl_41_data_10048[], lbl_41_data_100D8[];
extern char lbl_41_data_10168[];
}

extern "C" void* __ct__6emSparFUlP8emCreate(char* self, unsigned long arg0, emCreate* arg1) {
    char* s = self;
    Sub* b;
    Sub* a;

    fn_41_1F0(self, arg0, arg1, s + 0x5310, s + 0x5a6c, s + 0x5be0,
              s + 0x5d20, s + 0x5d68, s + 0x5e78, lbl_27_bss_A5C,
              s + 0x5e28, lbl_27_bss_69C);

    char* p = lbl_41_data_FAE8;
    *(char**)(s + 0x3c) = p;
    *(char**)(s + 0x40) = p + 0x64;
    *(char**)(s + 0x48) = p + 0x70;
    *(char**)(s + 0x54) = p + 0x84;
    *(char**)(s + 0x64) = p + 0xdc;
    *(char**)(s + 0x70) = p + 0xec;
    *(char**)(s + 0x7c) = p + 0x100;
    *(char**)(s + 0x88) = p + 0x114;
    *(char**)(s + 0x94) = p + 0x124;
    *(char**)(s + 0xa0) = p + 0x138;

    fn_27_D0568(s + 0x5310, 0x27, 0);
    fn_27_CA180(s + 0x5a6c, 0xa, 0);
    __construct_array(s + 0x5d20, (void*)__ct__18emTargetSearchUnitFv,
                      (void*)__dt__18emTargetSearchUnitFv, 0x18, 3);
    __construct_array(s + 0x5d68, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x18);
    fn_27_CB410(s + 0x5e28, 1, 0);

    Sub* a0 = (Sub*)(s + 0x5e78);
    a0->v0 = lbl_41_data_FD34;
    a0->v1 = lbl_41_data_FD34 + 0x10;
    a = a0 + 1;
    a->v0 = lbl_41_data_FF98;
    a->v1 = lbl_41_data_10048;
    Sub* t = a + 2;
    b = t - 1;
    (t - 1)->v0 = lbl_41_data_100D8;
    b->v1 = lbl_41_data_10168;

    fn_41_49EAC((char*)b + 0x0c, s + 0xdc);
    fn_41_49EAC((char*)b + 0x38, s + 0xdc);
    fn_41_49EAC((char*)a + 0x6c, s + 0xdc);

    a->v0 = lbl_41_data_FEB0;
    s[0x5f18] = 0;
    return self;
}