#pragma force_active on

struct emCreate;

extern "C" void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void fn_27_D00A0(void*, int, int);
extern "C" void fn_27_CADB4(void*, int, int);
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void __construct_array(void*, void*, void*, int, int);
extern "C" void* __ct__18emTargetSearchUnitFv(void*);
extern "C" void* __dt__18emTargetSearchUnitFv(void*, short);
extern "C" void* fn_41_2A470(void*);
extern "C" void* fn_41_2A480(void*, short);
extern "C" void fn_41_678C4(void*, void*);
extern "C" char lbl_27_bss_A5C[];
extern "C" char lbl_27_bss_69C[];
extern "C" char lbl_41_data_1DF88[];
extern "C" char lbl_41_data_1E1DC[];
extern "C" char lbl_41_data_1E360[];
extern "C" char lbl_41_data_1E448[];
extern "C" char lbl_41_data_1E4F8[];
extern "C" char lbl_41_data_1E588[];
extern "C" char lbl_41_data_1E618[];
extern "C" char lbl_41_data_1E6A8[];
extern "C" char lbl_41_data_1E738[];
extern "C" char lbl_41_data_1E7C8[];

struct Sub { void* v0; void* v1; };

extern "C" void* __ct__12emMasterhandFUlP8emCreate(char* self, unsigned long arg0, emCreate* arg1) {
    fn_41_1F0(self, arg0, arg1, self + 0x5310, self + 0x59dc, self + 0x5b08, self + 0x5c08,
              self + 0x5c38, self + 0x5d48, lbl_27_bss_A5C, self + 0x5cf8, lbl_27_bss_69C);
    char* p = lbl_41_data_1DF88;
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
    fn_27_D00A0(self + 0x5310, 0x24, 0);
    fn_27_CADB4(self + 0x59dc, 8, 0);
    __construct_array(self + 0x5c08, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 2);
    __construct_array(self + 0x5c38, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x18);
    fn_27_CB410(self + 0x5cf8, 1, 0);
    Sub* a0 = (Sub*)(self + 0x5d48);
    a0->v0 = lbl_41_data_1E1DC;
    a0->v1 = lbl_41_data_1E1DC + 0x10;
    Sub* b;
    Sub* c;
    Sub* a;
    Sub* t;
    Sub* u;
    a = a0 + 1;
    a->v0 = lbl_41_data_1E448;
    a->v1 = lbl_41_data_1E4F8;
    t = a + 2;
    b = t - 1;
    (t - 1)->v0 = lbl_41_data_1E588;
    b->v1 = lbl_41_data_1E618;
    u = b + 2;
    c = u - 1;
    (u - 1)->v0 = lbl_41_data_1E6A8;
    c->v1 = lbl_41_data_1E738;
    (c + 1)->v0 = lbl_41_data_1E7C8;
    fn_41_678C4((char*)c + 0x10, self + 0xdc);
    fn_41_678C4((char*)c + 0x3c, self + 0xdc);
    fn_41_678C4((char*)c + 0x68, self + 0xdc);
    fn_41_678C4((char*)b + 0x9c, self + 0xdc);
    fn_41_678C4((char*)b + 0xc8, self + 0xdc);
    fn_41_678C4((char*)a + 0xfc, self + 0xdc);
    a->v0 = lbl_41_data_1E360;
    self[0x5e78] = 0;
    return self;
}
