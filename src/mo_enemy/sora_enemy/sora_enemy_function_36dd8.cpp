#pragma force_active on
typedef unsigned char u8;

class emCreate;

extern "C" void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void fn_27_CE8B8(void*, int, int);
extern "C" void fn_27_CAFB8(void*, int, int);
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void __construct_array(void*, void*, void*, unsigned long, unsigned long);
extern "C" void* __ct__18emTargetSearchUnitFv(void*);
extern "C" void* __dt__18emTargetSearchUnitFv(void*, short);
extern "C" void* fn_41_2A470(void*);
extern "C" void* fn_41_2A480(void*, short);
extern "C" char lbl_27_bss_1F0[];
extern "C" char lbl_27_bss_A5C[];
extern "C" char lbl_27_bss_69C[];
extern "C" char lbl_41_data_7F98[];

class emRoada {
public:
    emRoada(unsigned long arg0, emCreate* arg1);
};

emRoada::emRoada(unsigned long arg0, emCreate* arg1) {
    u8* s = (u8*)this;
    fn_41_1F0(this, arg0, arg1, s + 0x5310, s + 0x564c, s + 0x579c, s + 0x58bc, s + 0x5904,
              lbl_27_bss_1F0, lbl_27_bss_A5C, s + 0x5a3c, lbl_27_bss_69C);
    u8* base = (u8*)lbl_41_data_7F98;
    *(u8**)(s + 0x3C) = base;
    *(u8**)(s + 0x40) = base + 0x64;
    *(u8**)(s + 0x48) = base + 0x70;
    *(u8**)(s + 0x54) = base + 0x84;
    *(u8**)(s + 0x64) = base + 0xDC;
    *(u8**)(s + 0x70) = base + 0xEC;
    *(u8**)(s + 0x7C) = base + 0x100;
    *(u8**)(s + 0x88) = base + 0x114;
    *(u8**)(s + 0x94) = base + 0x124;
    *(u8**)(s + 0xA0) = base + 0x138;
    fn_27_CE8B8(s + 0x5310, 0x11, 0);
    fn_27_CAFB8(s + 0x564c, 9, 0);
    __construct_array(s + 0x58bc, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 3);
    __construct_array(s + 0x5904, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x27);
    fn_27_CB410(s + 0x5a3c, 1, 0);
}
