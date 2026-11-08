#pragma force_active on

struct emCreate;
struct Sub { void* v0; void* v1; };

extern "C" void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void fn_27_D0898(void*, int, int);
extern "C" void fn_27_CAA84(void*, int, int);
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void __construct_array(void*, void*, void*, int, int);
extern "C" void* __ct__18emTargetSearchUnitFv(void*);
extern "C" void* __dt__18emTargetSearchUnitFv(void*, short);
extern "C" void* fn_41_2A470(void*);
extern "C" void* fn_41_2A480(void*, short);
extern "C" void fn_41_3FF0C(void*, void*);
extern "C" void fn_41_40190(void*, void*);
extern "C" char lbl_27_bss_A5C[];
extern "C" char lbl_27_bss_69C[];
extern "C" char lbl_41_data_C088[];
extern "C" char lbl_41_data_C2D4[];
extern "C" char lbl_41_data_C4FC[];
extern "C" char lbl_41_data_C64C[];
extern "C" char lbl_41_data_C7B4[];
extern "C" char lbl_41_data_C840[];
extern "C" char lbl_41_data_CA0C[];
extern "C" char lbl_41_data_CABC[];
extern "C" char lbl_41_data_CB4C[];
extern "C" char lbl_41_data_CBDC[];
extern "C" char lbl_41_data_CC6C[];
extern "C" char lbl_41_data_CCFC[];
extern "C" char lbl_41_data_CD8C[];

extern "C" void* __ct__6emPrimFUlP8emCreate(void* self, unsigned long arg0, emCreate* arg1) {
    char* s = (char*)self;
    fn_41_1F0(self, arg0, arg1, s + 0x5310, s + 0x5b5c, s + 0x5dcc, s + 0x5fec, s + 0x610c,
              s + 0x643c, lbl_27_bss_A5C, s + 0x63ec, lbl_27_bss_69C);

    char* p = lbl_41_data_C088;
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

    fn_27_D0898(s + 0x5310, 0x2c, 0);
    fn_27_CAA84(s + 0x5b5c, 0x11, 0);
    __construct_array(s + 0x5fec, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 0xc);
    __construct_array(s + 0x610c, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x5c);
    fn_27_CB410(s + 0x63ec, 1, 0);

    char* base = s + 0x643c;
    *(char**)(base) = lbl_41_data_C2D4;
    *(char**)(base + 4) = lbl_41_data_C2D4 + 0x10;
    *(char**)(base + 8) = lbl_41_data_CA0C;
    Sub* c;
    Sub* b;
    Sub* a;
    Sub* z = (Sub*)(base + 4);
    Sub* v = z + 2;
    a = v - 1;
    (v - 1)->v0 = lbl_41_data_CABC;
    a->v1 = lbl_41_data_CB4C;
    Sub* t = a + 2;
    b = t - 1;
    (t - 1)->v0 = lbl_41_data_CBDC;
    b->v1 = lbl_41_data_CC6C;
    Sub* u = b + 2;
    c = u - 1;
    (u - 1)->v0 = lbl_41_data_CCFC;
    c->v1 = lbl_41_data_CD8C;
    fn_41_3FF0C((char*)c + 0xc, s + 0xdc);
    fn_41_3FF0C((char*)c + 0x38, s + 0xdc);
    fn_41_3FF0C((char*)b + 0x6c, s + 0xdc);
    fn_41_3FF0C((char*)b + 0x98, s + 0xdc);
    fn_41_3FF0C((char*)a + 0xcc, s + 0xdc);
    fn_41_3FF0C((char*)a + 0xf8, s + 0xdc);

    *(char**)(base + 8) = lbl_41_data_C64C;
    Sub* w = (Sub*)(base + 0x128);
    Sub* x = w + 2;
    c = x - 1;
    (x - 1)->v0 = lbl_41_data_C7B4;
    c->v1 = lbl_41_data_C840;
    fn_41_40190((char*)c + 0xc, s + 0xdc);
    fn_41_40190((char*)c + 0x2384, s + 0xdc);
    *(char**)(base + 8) = lbl_41_data_C4FC;
    *(unsigned char*)(base + 0x482c) = 0;
    return self;
}
