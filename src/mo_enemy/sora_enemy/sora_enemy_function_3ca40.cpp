#pragma force_active on
struct emCreate;
struct Sub { void* v0; void* v1; };
extern "C" {
void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_CEBE8(void*, int, int);
void fn_27_CA3B8(void*, int, int);
void __construct_array(void*, void*, void*, unsigned long, unsigned long);
void fn_27_CB410(void*, int, int);
void fn_41_3CCC8(void*, void*);
void* __ct__18emTargetSearchUnitFv(void*);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_41_2A470(void*);
void* fn_41_2A480(void*, short);
extern char lbl_27_bss_A5C[], lbl_27_bss_69C[];
extern char lbl_41_data_AB08[], lbl_41_data_AD58[], lbl_41_data_AED4[];
extern char lbl_41_data_AFBC[], lbl_41_data_B068[], lbl_41_data_B0F4[], lbl_41_data_B180[];
}
extern "C" void* __ct__8emBotronFUlP8emCreate(char* self, unsigned long arg0, emCreate* arg1) {
    char* s = self;
    fn_41_1F0(self, arg0, arg1, s + 0x5310, s + 0x573c, s + 0x58d4,
              s + 0x5a34, s + 0x5a94, s + 0x5b84, lbl_27_bss_A5C,
              s + 0x5b34, lbl_27_bss_69C);
    char* p = lbl_41_data_AB08;
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
    fn_27_CEBE8(s + 0x5310, 0x16, 0);
    fn_27_CA3B8(s + 0x573c, 0xb, 0);
    __construct_array(s + 0x5a34, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 4);
    __construct_array(s + 0x5a94, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x14);
    fn_27_CB410(s + 0x5b34, 1, 0);
    Sub* a0 = (Sub*)(s + 0x5b84);
    a0->v0 = lbl_41_data_AD58;
    a0->v1 = lbl_41_data_AD58 + 0x10;
    Sub* b;
    Sub* a;
    Sub* t;
    a = a0 + 1;
    a->v0 = lbl_41_data_AFBC;
    a->v1 = lbl_41_data_B068;
    t = a + 2;
    b = t - 1;
    (t - 1)->v0 = lbl_41_data_B0F4;
    b->v1 = lbl_41_data_B180;
    fn_41_3CCC8((char*)b + 0xc, s + 0xdc);
    fn_41_3CCC8((char*)b + 0x38, s + 0xdc);
    fn_41_3CCC8((char*)a + 0x6c, s + 0xdc);
    a->v0 = lbl_41_data_AED4;
    s[0x5c24] = 0;
    return self;
}