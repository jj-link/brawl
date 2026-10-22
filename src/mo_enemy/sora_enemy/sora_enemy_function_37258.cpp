#pragma force_active on
extern "C" void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void fn_27_CEA50(void*, int, int);
extern "C" void fn_27_CAFB8(void*, int, int);
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void fn_27_63B94(void*, void*, int);
extern "C" void __construct_array(void*, void*, void*, int, int);
extern "C" void* __ct__18emTargetSearchUnitFv(void*);
extern "C" void* __dt__18emTargetSearchUnitFv(void*, short);
extern "C" void* fn_41_2A470(void*);
extern "C" void* fn_41_2A480(void*, short);
extern "C" char lbl_27_bss_1F0[];
extern "C" char lbl_27_bss_A5C[];
extern "C" char lbl_41_data_8268[];

struct emCreate;
struct emKiller;
extern "C" emKiller* __ct__8emKillerFUlP8emCreate(emKiller* self, unsigned long a, emCreate* b) {
    char* s = (char*)self;
    fn_41_1F0(self, a, b, s + 0x5310, s + 0x56AC, s + 0x57FC, s + 0x591C, s + 0x594C, lbl_27_bss_1F0, lbl_27_bss_A5C, s + 0x59B4, s + 0x5A04);
    char* p = lbl_41_data_8268;
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
    fn_27_CEA50(s + 0x5310, 0x13, 0);
    fn_27_CAFB8(s + 0x56AC, 9, 0);
    __construct_array(s + 0x591C, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 2);
    __construct_array(s + 0x594C, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0xd);
    fn_27_CB410(s + 0x59B4, 1, 0);
    fn_27_63B94(s + 0x5A04, s + 0xdc, 0);
    return self;
}