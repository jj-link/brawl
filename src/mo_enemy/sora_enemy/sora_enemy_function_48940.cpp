#pragma force_active on
extern "C" void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void fn_27_CFA40(void*, int, int);
extern "C" void fn_27_CA754(void*, int, int);
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void __construct_array(void*, void*, void*, int, int);
extern "C" void* __ct__18emTargetSearchUnitFv(void*);
extern "C" void* __dt__18emTargetSearchUnitFv(void*, short);
extern "C" void* fn_41_2A470(void*);
extern "C" void* fn_41_2A480(void*, short);
extern "C" char lbl_27_bss_1F0[];
extern "C" char lbl_27_bss_A5C[];
extern "C" char lbl_27_bss_69C[];
extern "C" char lbl_41_data_EFE8[];

struct emCreate;
struct emFlows;

extern "C" emFlows* __ct__7emFlowsFUlP8emCreate(emFlows* self, unsigned long a, emCreate* b) {
    char* s = (char*)self;
    fn_41_1F0(self, a, b, s + 0x5310, s + 0x58ec, s + 0x5acc, s + 0x5c6c, s + 0x5cb4,
              lbl_27_bss_1F0, lbl_27_bss_A5C, s + 0x5d34, lbl_27_bss_69C);
    char* p = lbl_41_data_EFE8;
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
    fn_27_CA754(s + 0x58ec, 0xd, 0);
    __construct_array(s + 0x5c6c, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 3);
    __construct_array(s + 0x5cb4, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x10);
    fn_27_CB410(s + 0x5d34, 1, 0);
    return self;
}