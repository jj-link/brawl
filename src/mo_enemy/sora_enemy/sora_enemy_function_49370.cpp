#pragma force_active on

struct emCreate;
struct emShelly;

extern "C" void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void fn_27_D0EF8(void*, int, int);
extern "C" void fn_27_CADB4(void*, int, int);
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void __construct_array(void*, void*, void*, unsigned long, unsigned long);
extern "C" void* __ct__18emTargetSearchUnitFv(void*);
extern "C" void* __dt__18emTargetSearchUnitFv(void*, short);
extern "C" void* fn_41_2A470(void*);
extern "C" void* fn_41_2A480(void*, short);

extern "C" char lbl_27_bss_1F0[];
extern "C" char lbl_27_bss_A5C[];
extern "C" char lbl_27_bss_69C[];
extern "C" char lbl_41_data_F588[];

extern "C" emShelly* __ct__8emShellyFUlP8emCreate(
    emShelly* self, unsigned long arg0, emCreate* arg1)
{
    char* s = (char*)self;

    fn_41_1F0(self, arg0, arg1,
              s + 0x5310, s + 0x5F1C, s + 0x6048,
              s + 0x6148, s + 0x6178,
              lbl_27_bss_1F0, lbl_27_bss_A5C,
              s + 0x6250, lbl_27_bss_69C);

    char* base = lbl_41_data_F588;
    *(char**)(s + 0x3C) = base;
    *(char**)(s + 0x40) = base + 0x64;
    *(char**)(s + 0x48) = base + 0x70;
    *(char**)(s + 0x54) = base + 0x84;
    *(char**)(s + 0x64) = base + 0xDC;
    *(char**)(s + 0x70) = base + 0xEC;
    *(char**)(s + 0x7C) = base + 0x100;
    *(char**)(s + 0x88) = base + 0x114;
    *(char**)(s + 0x94) = base + 0x124;
    *(char**)(s + 0xA0) = base + 0x138;

    fn_27_D0EF8(s + 0x5310, 0x40, 0);
    fn_27_CADB4(s + 0x5F1C, 8, 0);
    __construct_array(s + 0x6148,
                      (void*)__ct__18emTargetSearchUnitFv,
                      (void*)__dt__18emTargetSearchUnitFv,
                      0x18, 2);
    __construct_array(s + 0x6178,
                      (void*)fn_41_2A470,
                      (void*)fn_41_2A480,
                      8, 0x1B);
    fn_27_CB410(s + 0x6250, 1, 0);

    return self;
}
