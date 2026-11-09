#pragma force_active on
#include <types.h>
struct emCreate;
struct Sub { void* v0; void* v1; };
extern "C" {
void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_D0BC8(void*, int, int);
void fn_27_CADB4(void*, int, int);
void fn_27_CB410(void*, int, int);
void __construct_array(void*, void*, void*, int, int);
void* __ct__18emTargetSearchUnitFv(void*);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_41_2A470(void*);
void* fn_41_2A480(void*, short);
void fn_41_53084(void*, void*);
extern char lbl_27_bss_A5C[], lbl_27_bss_69C[];
extern char lbl_41_data_14118[], lbl_41_data_14368[], lbl_41_data_144E8[];
extern char lbl_41_data_145D0[], lbl_41_data_14680[], lbl_41_data_14710[];
extern char lbl_41_data_147A0[], lbl_41_data_14830[], lbl_41_data_148C0[];
}
extern "C" void* __ct__10emRobobeamFUlP8emCreate(void* self, unsigned long arg0, emCreate* arg1) {
    char* s = (char*)self;
    fn_41_1F0(self, arg0, arg1, s + 0x5310, s + 0x5D3C, s + 0x5E68, s + 0x5F68, s + 0x5F80, s + 0x6088, lbl_27_bss_A5C, s + 0x6038, lbl_27_bss_69C);
    char* p = lbl_41_data_14118;
    *(char**)(s + 0x3C) = p;
    *(char**)(s + 0x40) = p + 0x64;
    *(char**)(s + 0x48) = p + 0x70;
    *(char**)(s + 0x54) = p + 0x84;
    *(char**)(s + 0x64) = p + 0xDC;
    *(char**)(s + 0x70) = p + 0xEC;
    *(char**)(s + 0x7C) = p + 0x100;
    *(char**)(s + 0x88) = p + 0x114;
    *(char**)(s + 0x94) = p + 0x124;
    *(char**)(s + 0xA0) = p + 0x138;
    fn_27_D0BC8(s + 0x5310, 0x36, 0);
    fn_27_CADB4(s + 0x5D3C, 8, 0);
    __construct_array(s + 0x5F68, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 1);
    __construct_array(s + 0x5F80, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x17);
    fn_27_CB410(s + 0x6038, 1, 0);
    Sub* a0 = (Sub*)(s + 0x6088);
    a0->v0 = lbl_41_data_14368;
    a0->v1 = lbl_41_data_14368 + 0x10;
    Sub* b;
    Sub* c;
    Sub* a;
    Sub* t;
    Sub* u;
    a = a0 + 1;
    a->v0 = lbl_41_data_145D0;
    a->v1 = lbl_41_data_14680;
    t = a + 2;
    b = t - 1;
    (t - 1)->v0 = lbl_41_data_14710;
    b->v1 = lbl_41_data_147A0;
    u = b + 2;
    c = u - 1;
    (u - 1)->v0 = lbl_41_data_14830;
    c->v1 = lbl_41_data_148C0;
    fn_41_53084((char*)c + 0xc, s + 0xdc);
    fn_41_53084((char*)c + 0x38, s + 0xdc);
    fn_41_53084((char*)b + 0x6c, s + 0xdc);
    fn_41_53084((char*)b + 0x98, s + 0xdc);
    fn_41_53084((char*)a + 0xcc, s + 0xdc);
    a->v0 = lbl_41_data_144E8;
    s[0x6188] = 0;
    return self;
}