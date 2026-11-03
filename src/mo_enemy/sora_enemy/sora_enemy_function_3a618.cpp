#pragma force_active on

struct emCreate;

struct Sub { void* v0; void* v1; };

extern "C" {
extern char lbl_27_bss_A5C[];
extern char lbl_27_bss_69C[];
extern char lbl_41_data_9A78[];
extern char lbl_41_data_9CC8[];
extern char lbl_41_data_9E48[];
extern char lbl_41_data_9F30[];
extern char lbl_41_data_9FDC[];
extern char lbl_41_data_A068[];
extern char lbl_41_data_A0F4[];
extern char lbl_41_data_A180[];
extern char lbl_41_data_A20C[];
extern char lbl_41_data_A298[];

void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*,
                void*, void*, void*, void*, void*);
void fn_27_CE720(void*, int, int);
void fn_27_CA180(void*, int, int);
void fn_27_CB410(void*, int, int);
void __construct_array(void*, void*, void*, unsigned long, unsigned long);
void __ct__18emTargetSearchUnitFv();
void __dt__18emTargetSearchUnitFv();
void fn_41_2A470();
void fn_41_2A480();
void fn_41_3AA30(void*, void*);
}

extern "C" void* __ct__10emDeathpodFUlP8emCreate(
    char* self, unsigned long arg0, void* arg1
) {
    char* s = (char*)self;
    fn_41_1F0(self, arg0, arg1, s + 0x5310, s + 0x561c, s + 0x5790,
              s + 0x58d0, s + 0x5900, s + 0x59c8, lbl_27_bss_A5C,
              s + 0x5978, lbl_27_bss_69C);

    char* p = lbl_41_data_9A78;
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

    fn_27_CE720(s + 0x5310, 0x10, 0);
    fn_27_CA180(s + 0x561c, 0xa, 0);

    __construct_array(s + 0x58d0, (void*)__ct__18emTargetSearchUnitFv,
                      (void*)__dt__18emTargetSearchUnitFv, 0x18, 2);
    __construct_array(s + 0x5900, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0xf);
    fn_27_CB410(s + 0x5978, 1, 0);

    Sub* a0 = (Sub*)(s + 0x59c8);
    a0->v0 = lbl_41_data_9CC8;
    a0->v1 = lbl_41_data_9CC8 + 0x10;
    Sub* b;
    Sub* c;
    Sub* a;
    Sub* t;
    Sub* u;
    a = a0 + 1;
    a->v0 = lbl_41_data_9F30;
    a->v1 = lbl_41_data_9FDC;
    t = a + 2;
    b = t - 1;
    (t - 1)->v0 = lbl_41_data_A068;
    b->v1 = lbl_41_data_A0F4;
    u = b + 2;
    c = u - 1;
    (u - 1)->v0 = lbl_41_data_A180;
    c->v1 = lbl_41_data_A20C;
    *(char**)(s + 0x59e8) = lbl_41_data_A298;

    fn_41_3AA30((char*)c + 0x10, s + 0xdc);
    fn_41_3AA30((char*)c + 0x3c, s + 0xdc);
    fn_41_3AA30((char*)c + 0x68, s + 0xdc);
    fn_41_3AA30((char*)b + 0x9c, s + 0xdc);
    fn_41_3AA30((char*)b + 0xc8, s + 0xdc);
    fn_41_3AA30((char*)a + 0xfc, s + 0xdc);

    a->v0 = lbl_41_data_9E48;
    s[0x5af8] = 0;
    return self;
}
