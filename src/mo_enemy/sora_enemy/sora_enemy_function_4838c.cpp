#pragma force_active on
extern "C" void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void fn_27_CFD70(void*, int, int);
extern "C" void fn_27_CAFB8(void*, int, int);
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void __construct_array(void*, void*, void*, int, int);
extern "C" void* __ct__18emTargetSearchUnitFv(void*);
extern "C" void* __dt__18emTargetSearchUnitFv(void*, short);
extern "C" void* fn_41_2A470(void*);
extern "C" void* fn_41_2A480(void*, short);
extern "C" char lbl_27_bss_1F0[];
extern "C" char lbl_27_bss_A5C[];
extern "C" char lbl_27_bss_69C[];
extern "C" char lbl_41_data_ED38[];

struct emCreate;
struct emKuribo;

extern "C" emKuribo* __ct__8emKuriboFUlP8emCreate(emKuribo* self, unsigned long a, emCreate* b) {
    char* s = (char*)self;
    fn_41_1F0(self, a, b, s + 0x5310, s + 0x594c, s + 0x5a9c, s + 0x5bbc, s + 0x5bec,
              lbl_27_bss_1F0, lbl_27_bss_A5C, s + 0x5cd4, lbl_27_bss_69C);
    char* p = lbl_41_data_ED38;
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
    fn_27_CFD70(s + 0x5310, 0x21, 0);
    fn_27_CAFB8(s + 0x594c, 9, 0);
    __construct_array(s + 0x5bbc, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 2);
    __construct_array(s + 0x5bec, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x1d);
    fn_27_CB410(s + 0x5cd4, 1, 0);
    return self;
}
