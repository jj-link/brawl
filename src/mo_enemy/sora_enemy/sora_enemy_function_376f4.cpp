#pragma force_active on
#include <types.h>
struct emCreate;
struct Sub { void* v0; void* v1; };
extern "C" {
void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_CED80(void*, int, int);
void fn_27_CAFB8(void*, int, int);
void fn_27_CB410(void*, int, int);
void __construct_array(void*, void*, void*, int, int);
void* __ct__18emTargetSearchUnitFv(void*);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_41_2A470(void*);
void* fn_41_2A480(void*, short);
void fn_41_37A88(void*, void*);
extern char lbl_27_bss_A5C[], lbl_27_bss_69C[];
extern char lbl_41_data_853C[], lbl_41_data_878C[], lbl_41_data_890C[];
extern char lbl_41_data_89F4[], lbl_41_data_8AA0[], lbl_41_data_8B2C[];
extern char lbl_41_data_8BB8[], lbl_41_data_8C44[], lbl_41_data_8CD0[];
}
extern "C" void* __ct__10emPopperamFUlP8emCreate(char* self, unsigned long arg0, emCreate* arg1) {
    fn_41_1F0(self, arg0, arg1, self + 0x5310, self + 0x576c, self + 0x58bc, self + 0x59dc, self + 0x5a24,
              self + 0x5b44, lbl_27_bss_A5C, self + 0x5af4, lbl_27_bss_69C);
    char* p = lbl_41_data_853C;
    *(char**)(self + 0x3c) = p;
    *(char**)(self + 0x40) = p + 0x64;
    *(char**)(self + 0x48) = p + 0x70;
    *(char**)(self + 0x54) = p + 0x84;
    *(char**)(self + 0x64) = p + 0xdc;
    *(char**)(self + 0x70) = p + 0xec;
    *(char**)(self + 0x7c) = p + 0x100;
    *(char**)(self + 0x88) = p + 0x114;
    *(char**)(self + 0x94) = p + 0x124;
    *(char**)(self + 0xa0) = p + 0x138;
    fn_27_CED80(self + 0x5310, 0x17, 0);
    fn_27_CAFB8(self + 0x576c, 9, 0);
    __construct_array(self + 0x59dc, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 3);
    __construct_array(self + 0x5a24, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x1a);
    fn_27_CB410(self + 0x5af4, 1, 0);
    Sub* a0 = (Sub*)(self + 0x5b44);
    a0->v0 = lbl_41_data_878C;
    a0->v1 = lbl_41_data_878C + 0x10;
    Sub* b;
    Sub* c;
    Sub* a;
    Sub* t;
    Sub* u;
    a = a0 + 1;
    a->v0 = lbl_41_data_89F4;
    a->v1 = lbl_41_data_8AA0;
    t = a + 2;
    b = t - 1;
    (t - 1)->v0 = lbl_41_data_8B2C;
    b->v1 = lbl_41_data_8BB8;
    u = b + 2;
    c = u - 1;
    (u - 1)->v0 = lbl_41_data_8C44;
    c->v1 = lbl_41_data_8CD0;
    fn_41_37A88((char*)c + 0xc, self + 0xdc);
    fn_41_37A88((char*)c + 0x38, self + 0xdc);
    fn_41_37A88((char*)b + 0x6c, self + 0xdc);
    fn_41_37A88((char*)b + 0x98, self + 0xdc);
    fn_41_37A88((char*)a + 0xcc, self + 0xdc);
    a->v0 = lbl_41_data_890C;
    self[0x5c44] = 0;
    return self;
}