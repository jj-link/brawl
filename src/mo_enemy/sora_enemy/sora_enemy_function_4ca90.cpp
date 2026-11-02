#pragma force_active on

struct emCreate;

extern "C" void fn_41_1F0(void*, unsigned long,
                          void*, void*, void*, void*, void*,
                          void*, void*, void*, void*, void*);
extern "C" void fn_27_CF578(void*, int, int);
extern "C" void fn_27_CAFB8(void*, int, int);
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void __construct_array(void*, void*, void*, int, int);
extern "C" void* __ct__18emTargetSearchUnitFv(void*);
extern "C" void* __dt__18emTargetSearchUnitFv(void*, short);
extern "C" void* fn_41_2A470(void*);
extern "C" void* fn_41_2A480(void*, short);
extern "C" void* fn_41_4CE24(void*, void*);
extern "C" char lbl_27_bss_A5C[];
extern "C" char lbl_27_bss_69C[];
extern "C" char lbl_41_data_11180[];
extern "C" char lbl_41_data_113D0[];
extern "C" char lbl_41_data_11550[];
extern "C" char lbl_41_data_11638[];
extern "C" char lbl_41_data_116E8[];
extern "C" char lbl_41_data_11778[];
extern "C" char lbl_41_data_11808[];
extern "C" char lbl_41_data_11898[];
extern "C" char lbl_41_data_11928[];

struct Sub { void* v0; void* v1; };

extern "C" void* __ct__8emKokkonFUlP8emCreate(void* self, unsigned long arg0, emCreate* arg1) {
    char* s = (char*)self;
    fn_41_1F0(self, arg0, arg1, s + 0x5310, s + 0x585c, s + 0x59ac, s + 0x5acc, s + 0x5afc,
              s + 0x5bdc, lbl_27_bss_A5C, s + 0x5b8c, lbl_27_bss_69C);

    char* p = lbl_41_data_11180;
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

    fn_27_CF578(s + 0x5310, 0x1c, 0);
    fn_27_CAFB8(s + 0x585c, 9, 0);
    __construct_array(s + 0x5acc, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 2);
    __construct_array(s + 0x5afc, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x12);
    fn_27_CB410(s + 0x5b8c, 1, 0);

    Sub* a0 = (Sub*)(s + 0x5bdc);
    a0->v0 = lbl_41_data_113D0;
    a0->v1 = lbl_41_data_113D0 + 0x10;

    Sub* b;
    Sub* c;
    Sub* a;
    Sub* t;
    Sub* u;
    a = a0 + 1;
    a->v0 = lbl_41_data_11638;
    a->v1 = lbl_41_data_116E8;
    t = a + 2;
    b = t - 1;
    (t - 1)->v0 = lbl_41_data_11778;
    b->v1 = lbl_41_data_11808;
    u = b + 2;
    c = u - 1;
    (u - 1)->v0 = lbl_41_data_11898;
    c->v1 = lbl_41_data_11928;

    fn_41_4CE24((char*)c + 0xc, s + 0xdc);
    fn_41_4CE24((char*)c + 0x38, s + 0xdc);
    fn_41_4CE24((char*)b + 0x6c, s + 0xdc);
    fn_41_4CE24((char*)b + 0x98, s + 0xdc);
    fn_41_4CE24((char*)a + 0xcc, s + 0xdc);

    a->v0 = lbl_41_data_11550;
    s[0x5cdc] = 0;
    return self;
}
