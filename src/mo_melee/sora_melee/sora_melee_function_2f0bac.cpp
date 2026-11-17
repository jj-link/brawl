#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3(void*, int, void*, int);
    virtual void slot4();
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
extern char lbl_27_bss_7544[];
extern char lbl_27_data_13730[];
extern char lbl_27_data_7EA70[];
extern char lbl_27_data_7EA7C[];
extern char lbl_27_data_7ED90[];
extern float lbl_27_rodata_64C0;
extern float lbl_27_rodata_64C4;

void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_1D8FC8(void*, int);
void fn_27_1D90FC(void*);
void fn_27_1DBA64(void*);
void fn_27_2E7828(void*, void*, void*);
void fn_27_2F0EF4(void*, void*, void*);
}

extern "C" void* fn_27_2F0BAC(void* arg0, int arg1, void* arg2, const int* arg3) {
    struct ShortSlot {
        short value;
        short padding;
    };

    ShortSlot sp2c;
    ShortSlot sp28;
    void* sp30[2];
    int sp78[16];
    float tbl[15];

    char* self = (char*)arg0;
    int t23;
    Object_vptr_0* r24 = *(Object_vptr_0**)((char*)arg2 + 4);
    t23 = r24->slot5();
    int t6 = r24->slot2();

    fn_27_1DC5E8(sp78, 0x56, arg3, t6, 0x1f, t23,
                 *arg3 & 0xff, 0, g_soParamAccesserNull,
                 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_7EA70, sp78[1], sp78[2],
                 arg1, arg2, self + 0x544, 1);

    char* modules = self + 0xcc;
    char* p = lbl_27_data_7ED90;
    *(void**)(self + 0x3c) = p;
    *(void**)(self + 0x40) = p + 0x64;
    *(void**)(self + 0x48) = p + 0x70;
    *(void**)(self + 0x54) = p + 0x84;
    *(void**)(self + 0x64) = p + 0xdc;
    *(void**)(self + 0x70) = p + 0xec;
    *(void**)(self + 0x7c) = p + 0x100;
    *(void**)(self + 0x88) = p + 0x118;
    *(void**)(self + 0x90) = p + 0x124;
    fn_27_2F0EF4(modules, self, sp78);
    fn_27_2E7828(modules + 0x1454, modules + 0x478, sp78);
    fn_27_1DBA64(self + 0x1878);

    tbl[12] = lbl_27_rodata_64C0;
    tbl[9] = lbl_27_rodata_64C4;
    tbl[13] = lbl_27_rodata_64C0;
    tbl[14] = lbl_27_rodata_64C0;
    tbl[10] = lbl_27_rodata_64C4;
    tbl[11] = lbl_27_rodata_64C4;
    tbl[6] = lbl_27_rodata_64C0;
    tbl[7] = lbl_27_rodata_64C0;
    tbl[8] = lbl_27_rodata_64C0;
    tbl[3] = lbl_27_rodata_64C4;
    tbl[4] = lbl_27_rodata_64C4;
    tbl[5] = lbl_27_rodata_64C4;
    tbl[0] = lbl_27_rodata_64C4;
    tbl[1] = lbl_27_rodata_64C4;
    tbl[2] = lbl_27_rodata_64C4;
    int* ti = (int*)tbl;

    struct FlagByte {
        unsigned char flag : 1;
        unsigned char rest : 7;
    };
    *(unsigned char*)(self + 0x18B4) = 0;
    ((FlagByte*)(self + 0x18B5))->flag = 1;
    *(unsigned char*)(self + 0x18B6) = 0;
    *(void**)(self + 0x18B0) = lbl_27_data_13730;
    *(int*)(self + 0x18B8) = ti[0];
    *(int*)(self + 0x18BC) = ti[1];
    *(int*)(self + 0x18C0) = ti[2];
    *(int*)(self + 0x18C4) = ti[3];
    *(int*)(self + 0x18C8) = ti[4];
    *(int*)(self + 0x18CC) = ti[5];
    *(int*)(self + 0x18D0) = ti[6];
    *(int*)(self + 0x18D4) = ti[7];
    *(int*)(self + 0x18D8) = ti[8];
    *(int*)(self + 0x18DC) = ti[9];
    *(int*)(self + 0x18E0) = ti[10];
    *(int*)(self + 0x18E4) = ti[11];
    *(int*)(self + 0x18E8) = ti[12];
    *(int*)(self + 0x18EC) = ti[13];
    *(int*)(self + 0x18F0) = ti[14];
    fn_27_1D90FC(self);

    sp28.value = 1;
    Object_vptr_0* o1 = *(Object_vptr_0**)(
        *(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    o1->slot3(self + 0x1878, 0, &sp28, -1);

    sp2c.value = 1;
    o1 = *(Object_vptr_0**)(
        *(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c);
    o1->slot3(self + 0x18B0, 1, &sp2c, -1);

    char* q = lbl_27_data_7EA7C;
    *(void**)(self + 0x3c) = q;
    *(void**)(self + 0x40) = q + 0x64;
    *(void**)(self + 0x48) = q + 0x70;
    *(void**)(self + 0x54) = q + 0x84;
    *(void**)(self + 0x64) = q + 0xdc;
    *(void**)(self + 0x70) = q + 0xec;
    *(void**)(self + 0x7c) = q + 0x100;
    *(void**)(self + 0x88) = q + 0x118;
    *(void**)(self + 0x90) = q + 0x124;

    sp30[0] = lbl_27_bss_7544;
    sp30[1] = lbl_27_bss_7544;
    Object_vptr_0* o2 = *(Object_vptr_0**)(
        *(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70);
    o2->slot28(sp30, 2);

    fn_27_1D8FC8(self, 0);
    return arg0;
}
