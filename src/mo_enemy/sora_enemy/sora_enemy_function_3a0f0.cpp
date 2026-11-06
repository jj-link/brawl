#pragma force_active on
typedef unsigned char u8;

class emCreate;

extern "C" void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void fn_27_CE3F0(void*, int, int);
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
extern "C" char lbl_41_data_97C8[];

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(unsigned long arg);
};

class emCymal {
public:
    emCymal(unsigned long arg0, emCreate* arg1);
};

emCymal::emCymal(unsigned long arg0, emCreate* arg1) {
    u8* s = (u8*)this;
    fn_41_1F0(this, arg0, arg1, s + 0x5310, s + 0x55bc, s + 0x56e8, s + 0x57e8, s + 0x5800,
              lbl_27_bss_1F0, lbl_27_bss_A5C, s + 0x5868, lbl_27_bss_69C);
    u8* base = (u8*)lbl_41_data_97C8;
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
    fn_27_CE3F0(s + 0x5310, 0xe, 0);
    fn_27_CADB4(s + 0x55bc, 8, 0);
    __construct_array(s + 0x57e8, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 1);
    __construct_array(s + 0x5800, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0xd);
    fn_27_CB410(s + 0x5868, 1, 0);
    u8* a = *(u8**)(s + 0x60);
    u8* b = *(u8**)(a + 0xd8);
    Object_vptr_0* c = *(Object_vptr_0**)(b + 0x64);
    c->slot19(0x12000006);
}