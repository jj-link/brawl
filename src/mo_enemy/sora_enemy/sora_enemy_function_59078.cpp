#pragma force_active on
struct emCreate;
struct emBosspackun;
struct Sub { void* v0; void* v1; };
extern "C" {
void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_CFA40(void*, int, int);
void fn_27_CAC1C(void*, int, int);
void fn_27_CB410(void*, int, int);
void __construct_array(void*, void*, void*, int, int);
void* __ct__18emTargetSearchUnitFv(void*);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_41_2A470(void*);
void* fn_41_2A480(void*, short);
void* fn_41_5927C(void*, void*);
extern char lbl_27_bss_A5C[];
extern char lbl_27_bss_69C[];
extern char lbl_41_data_17368[];
extern char lbl_41_data_175BC[];
extern char lbl_41_data_17820[];
extern char lbl_41_data_178CC[];
extern char lbl_41_data_17958[];
extern char lbl_41_data_1773C[];
}
extern "C" emBosspackun* __ct__12emBosspackunFUlP8emCreate(emBosspackun* self, unsigned long a, emCreate* b) {
    char* s = (char*)self;
    fn_41_1F0(self, a, b, s + 0x5310, s + 0x58ec, s + 0x59f4, s + 0x5ad4, s + 0x5aec,
              s + 0x5c34, lbl_27_bss_A5C, s + 0x5be4, lbl_27_bss_69C);
    char* p = lbl_41_data_17368;
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
    fn_27_CFA40(s + 0x5310, 0x1f, 0);
    fn_27_CAC1C(s + 0x58ec, 7, 0);
    __construct_array(s + 0x5ad4, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 1);
    __construct_array(s + 0x5aec, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x1f);
    fn_27_CB410(s + 0x5be4, 1, 0);
    Sub* a0 = (Sub*)(s + 0x5c34);
    a0->v0 = lbl_41_data_175BC;
    a0->v1 = lbl_41_data_175BC + 0x10;
    Sub* aa = a0 + 1;
    aa->v0 = lbl_41_data_17820;
    Sub* t = aa + 1;
    char* sub = (char*)t - 4;
    *(char**)sub = lbl_41_data_178CC;
    *(char**)(sub + 4) = lbl_41_data_17958;
    fn_41_5927C(sub + 0xc, s + 0xdc);
    fn_41_5927C(sub + 0x2384, s + 0xdc);
    a0[1].v0 = lbl_41_data_1773C;
    ((char*)a0)[0x4708] = 0;
    return self;
}