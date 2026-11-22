#include <types.h>
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
    virtual void slot28(void**, int);
};
struct Arg2 { int pad; Object_vptr_0* heap; };
struct Build { int data[16]; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
struct ShortSlot { short n; short pad; };

extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_data_13730[], lbl_27_data_7DCC0[], lbl_27_data_7DCD0[], lbl_27_data_7DFE0[];
extern char lbl_27_bss_7504[];
extern float lbl_27_rodata_6448, lbl_27_rodata_644C;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_2EC1B4(void*, void*, void*);
void fn_27_2E7828(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}
extern "C" void* fn_27_2EBE4C(char* self, int arg1, Arg2* arg2, const int* arg3) {
    Build build;
    float tbl[15];
    void* process[2];
    ShortSlot m;
    ShortSlot n;
    int t22;
    int t23;
    Object_vptr_0* r24 = *(Object_vptr_0**)((char*)arg2 + 4);
    t23 = r24->slot5();
    t22 = r24->slot4();
    int t6 = r24->slot2();
    unsigned char id = *arg3 & 0xff;
    fn_27_1DC5E8(&build, 0x55, arg3, t6, t22, t23, id, -1,
                 g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_7DCC0, build.data[1], build.data[2], arg1, arg2,
                 self + 0x544, 1);
    char* sub = self + 0xcc;
    *(char**)(self + 0x3c) = lbl_27_data_7DFE0;
    *(char**)(self + 0x40) = lbl_27_data_7DFE0 + 0x64;
    *(char**)(self + 0x48) = lbl_27_data_7DFE0 + 0x70;
    *(char**)(self + 0x54) = lbl_27_data_7DFE0 + 0x84;
    *(char**)(self + 0x64) = lbl_27_data_7DFE0 + 0xdc;
    *(char**)(self + 0x70) = lbl_27_data_7DFE0 + 0xec;
    *(char**)(self + 0x7c) = lbl_27_data_7DFE0 + 0x100;
    *(char**)(self + 0x88) = lbl_27_data_7DFE0 + 0x118;
    *(char**)(self + 0x90) = lbl_27_data_7DFE0 + 0x124;
    fn_27_2EC1B4(sub, self, &build);
    fn_27_2E7828(sub + 0x1480, sub + 0x478, &build);
    fn_27_1DBA64(self + 0x18a4);

    tbl[12] = lbl_27_rodata_6448;
    tbl[9] = lbl_27_rodata_644C;
    tbl[13] = lbl_27_rodata_6448;
    tbl[14] = lbl_27_rodata_6448;
    tbl[10] = lbl_27_rodata_644C;
    tbl[11] = lbl_27_rodata_644C;
    tbl[6] = lbl_27_rodata_6448;
    tbl[7] = lbl_27_rodata_6448;
    tbl[8] = lbl_27_rodata_6448;
    tbl[3] = lbl_27_rodata_644C;
    tbl[4] = lbl_27_rodata_644C;
    tbl[5] = lbl_27_rodata_644C;
    tbl[0] = lbl_27_rodata_644C;
    tbl[1] = lbl_27_rodata_644C;
    tbl[2] = lbl_27_rodata_644C;
    int* ti = (int*)tbl;
    self[0x18e0] = 0;
    ((FlagByte*)(self + 0x18e1))->flag = 1;
    self[0x18e2] = 0;
    *(char**)(self + 0x18dc) = lbl_27_data_13730;
    *(int*)(self + 0x18e4) = ti[0];
    *(int*)(self + 0x18e8) = ti[1];
    *(int*)(self + 0x18ec) = ti[2];
    *(int*)(self + 0x18f0) = ti[3];
    *(int*)(self + 0x18f4) = ti[4];
    *(int*)(self + 0x18f8) = ti[5];
    *(int*)(self + 0x18fc) = ti[6];
    *(int*)(self + 0x1900) = ti[7];
    *(int*)(self + 0x1904) = ti[8];
    *(int*)(self + 0x1908) = ti[9];
    *(int*)(self + 0x190c) = ti[10];
    *(int*)(self + 0x1910) = ti[11];
    *(int*)(self + 0x1914) = ti[12];
    *(int*)(self + 0x1918) = ti[13];
    *(int*)(self + 0x191c) = ti[14];
    fn_27_1D90FC(self);

    n.n = 1;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))
        ->slot3(self + 0x18a4, 0, &n.n, -1);
    m.n = 1;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))
        ->slot3(self + 0x18dc, 1, &m.n, -1);

    char* s = lbl_27_data_7DCD0;
    *(char**)(self + 0x3c) = s;
    *(char**)(self + 0x40) = s + 0x64;
    *(char**)(self + 0x48) = s + 0x70;
    *(char**)(self + 0x54) = s + 0x84;
    *(char**)(self + 0x64) = s + 0xdc;
    *(char**)(self + 0x70) = s + 0xec;
    *(char**)(self + 0x7c) = s + 0x100;
    *(char**)(self + 0x88) = s + 0x118;
    *(char**)(self + 0x90) = s + 0x124;
    *(int*)(self + 0x1920) = arg3[13];
    process[0] = lbl_27_bss_7504;
    process[1] = lbl_27_bss_7504;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70))
        ->slot28(process, 2);
    fn_27_1D8FC8(self, 0);
    return self;
}