#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3(void*, int, short*, int);
    virtual int slot4();
    virtual int slot5();
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
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28(void*, int);
};
extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_bss_765C[];
extern char lbl_27_data_13730[];
extern char lbl_27_data_81100[];
extern char lbl_27_data_8112C[];
extern char lbl_27_data_81398[];
extern float lbl_27_rodata_6530;
extern float lbl_27_rodata_6534;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_1D8FC8(void*, int);
void fn_27_1D90FC(void*);
void fn_27_1DBA64(void*);
void fn_27_2FCB00(void*, void*, void*);
void fn_27_2FDD48(void*, void*, void*);
}
struct F15 { float v[15]; };
extern "C" void* fn_27_2FC784(void* arg0, int arg1, void* arg2, const int* arg3) {
    struct ShortSlot { short value; short padding; };
    ShortSlot sp2c;
    ShortSlot sp28;
    void* spb0[9];
    int params[16];
    float tbl[15];

    char* self = (char*)arg0;
    int t23;
    int t24;
    Object_vptr_0* obj = *(Object_vptr_0**)((char*)arg2 + 4);
    t24 = obj->slot5();
    t23 = obj->slot4();
    int t6 = obj->slot2();

    fn_27_1DC5E8(params, 0x53, arg3, t6, t23, t24,
                 *arg3 & 0xff, 0, g_soParamAccesserNull,
                 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_81100, params[1], params[2],
                 arg1, arg2, self + 0x544, 1);

    char* modules = self + 0xcc;
    char* p = lbl_27_data_81398;
    *(void**)(self + 0x3c) = p;
    *(void**)(self + 0x40) = p + 0x64;
    *(void**)(self + 0x48) = p + 0x70;
    *(void**)(self + 0x54) = p + 0x84;
    *(void**)(self + 0x64) = p + 0xdc;
    *(void**)(self + 0x70) = p + 0xec;
    *(void**)(self + 0x7c) = p + 0x100;
    *(void**)(self + 0x88) = p + 0x118;
    *(void**)(self + 0x90) = p + 0x124;
    fn_27_2FCB00(modules, self, params);
    fn_27_2FDD48(modules + 0x1388, modules + 0x478, params);
    fn_27_1DBA64(self + 0x17ac);

    tbl[12] = lbl_27_rodata_6530;
    tbl[9] = lbl_27_rodata_6534;
    tbl[13] = lbl_27_rodata_6530;
    tbl[14] = lbl_27_rodata_6530;
    tbl[10] = lbl_27_rodata_6534;
    tbl[11] = lbl_27_rodata_6534;
    tbl[6] = lbl_27_rodata_6530;
    tbl[7] = lbl_27_rodata_6530;
    tbl[8] = lbl_27_rodata_6530;
    tbl[3] = lbl_27_rodata_6534;
    tbl[4] = lbl_27_rodata_6534;
    tbl[5] = lbl_27_rodata_6534;
    tbl[0] = lbl_27_rodata_6534;
    tbl[1] = lbl_27_rodata_6534;
    tbl[2] = lbl_27_rodata_6534;
    struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
    self[0x17e8] = 0;
    ((FlagByte*)(self + 0x17e9))->flag = 1;
    self[0x17ea] = 0;
    *(void**)(self + 0x17e4) = lbl_27_data_13730;
    *(F15*)(self + 0x17ec) = *(F15*)tbl;
    fn_27_1D90FC(self);

    sp28.value = 1;
    Object_vptr_0* o = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    o->slot3(self + 0x17ac, 0, &sp28.value, -1);
    sp2c.value = 1;
    o = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    o->slot3(self + 0x17e4, 1, &sp2c.value, -1);

    char* q = lbl_27_data_8112C;
    *(void**)(self + 0x3c) = q;
    *(void**)(self + 0x40) = q + 0x64;
    *(void**)(self + 0x48) = q + 0x70;
    *(void**)(self + 0x54) = q + 0x84;
    *(void**)(self + 0x64) = q + 0xdc;
    *(void**)(self + 0x70) = q + 0xec;
    *(void**)(self + 0x7c) = q + 0x100;
    *(void**)(self + 0x88) = q + 0x118;
    *(void**)(self + 0x90) = q + 0x124;
    spb0[0] = lbl_27_bss_765C;
    spb0[1] = lbl_27_bss_765C;
    spb0[2] = lbl_27_bss_765C;
    spb0[3] = lbl_27_bss_765C;
    spb0[4] = lbl_27_bss_765C;
    spb0[5] = lbl_27_bss_765C;
    spb0[6] = lbl_27_bss_765C;
    spb0[7] = lbl_27_bss_765C;
    spb0[8] = lbl_27_bss_765C;
    o = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70);
    o->slot28(spb0, 9);
    fn_27_1D8FC8(self, 0);
    return arg0;
}