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
    virtual void slot28(void*, int);
};

struct Build { int data[16]; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
struct ShortSlot { short n; short pad; };
struct Pair { void* a; int b; };

extern "C" {
extern char lbl_27_data_8DB40[];
extern char lbl_27_data_8DB54[];
extern char lbl_27_data_8DDC0[];
extern char lbl_27_data_8E02C[];
extern char lbl_27_data_13730[];
extern char lbl_27_bss_7FA4[];
extern float lbl_27_rodata_7930;
extern float lbl_27_rodata_7934;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_34F0DC(void*, void*, void*);
void fn_27_34FEE8(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1F980(void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void* fn_27_34E94C(char* self, int arg1, void* arg2, const int* arg3) {
    Build build;
    float tbl[15];
    Pair pair;
    ShortSlot m;
    ShortSlot n;
    int t22;
    int t23;

    Object_vptr_0* r24 = *(Object_vptr_0**)((char*)arg2 + 4);
    t23 = r24->slot5();
    t22 = r24->slot4();
    int t6 = r24->slot2();
    unsigned char id = *arg3 & 0xff;
    fn_27_1DC5E8(&build, 0x75, arg3, t6, t22, t23, id, -1,
                 self + 0x214c, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_8DB40, build.data[1], build.data[2], arg1, arg2,
                 self + 0x8c4, 1);

    char* sub = self + 0xcc;
    *(char**)(self + 0x3c) = lbl_27_data_8DDC0;
    *(char**)(self + 0x40) = lbl_27_data_8DDC0 + 0x64;
    *(char**)(self + 0x48) = lbl_27_data_8DDC0 + 0x70;
    *(char**)(self + 0x54) = lbl_27_data_8DDC0 + 0x84;
    *(char**)(self + 0x64) = lbl_27_data_8DDC0 + 0xdc;
    *(char**)(self + 0x70) = lbl_27_data_8DDC0 + 0xec;
    *(char**)(self + 0x7c) = lbl_27_data_8DDC0 + 0x100;
    *(char**)(self + 0x88) = lbl_27_data_8DDC0 + 0x118;
    *(char**)(self + 0x90) = lbl_27_data_8DDC0 + 0x124;
    fn_27_34F0DC(sub, self, &build);
    fn_27_34FEE8(sub + 0x1a50, sub + 0x7f8, &build);
    fn_27_1DBA64(self + 0x20cc);

    tbl[12] = lbl_27_rodata_7930;
    tbl[9] = lbl_27_rodata_7934;
    tbl[13] = lbl_27_rodata_7930;
    tbl[14] = lbl_27_rodata_7930;
    tbl[10] = lbl_27_rodata_7934;
    tbl[11] = lbl_27_rodata_7934;
    tbl[6] = lbl_27_rodata_7930;
    tbl[7] = lbl_27_rodata_7930;
    tbl[8] = lbl_27_rodata_7930;
    tbl[3] = lbl_27_rodata_7934;
    tbl[4] = lbl_27_rodata_7934;
    tbl[5] = lbl_27_rodata_7934;
    tbl[0] = lbl_27_rodata_7934;
    tbl[1] = lbl_27_rodata_7934;
    tbl[2] = lbl_27_rodata_7934;
    int* ti = (int*)tbl;

    self[0x2108] = 0;
    ((FlagByte*)(self + 0x2109))->flag = 1;
    self[0x210a] = 0;
    *(char**)(self + 0x2104) = lbl_27_data_13730;
    *(int*)(self + 0x210c) = ti[0];
    *(int*)(self + 0x2110) = ti[1];
    *(int*)(self + 0x2114) = ti[2];
    *(int*)(self + 0x2118) = ti[3];
    *(int*)(self + 0x211c) = ti[4];
    *(int*)(self + 0x2120) = ti[5];
    *(int*)(self + 0x2124) = ti[6];
    *(int*)(self + 0x2128) = ti[7];
    *(int*)(self + 0x212c) = ti[8];
    *(int*)(self + 0x2130) = ti[9];
    *(int*)(self + 0x2134) = ti[10];
    *(int*)(self + 0x2138) = ti[11];
    *(int*)(self + 0x213c) = ti[12];
    *(int*)(self + 0x2140) = ti[13];
    *(int*)(self + 0x2144) = ti[14];
    fn_27_1D90FC(self);

    n.n = 1;
    ((Object_vptr_0*)*(char**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))
        ->slot3(self + 0x20cc, 0, &n.n, -1);
    m.n = 1;
    ((Object_vptr_0*)*(char**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))
        ->slot3(self + 0x2104, 1, &m.n, -1);

    char* e = lbl_27_data_8DB54;
    char* e64 = e + 0x64;
    char* e70 = e + 0x70;
    char* e84 = e + 0x84;
    char* edc = e + 0xdc;
    char* eec = e + 0xec;
    char* e100 = e + 0x100;
    char* e118 = e + 0x118;
    char* e124 = e + 0x124;

    *(char**)(self + 0x3c) = e;
    *(char**)(self + 0x40) = e64;
    *(char**)(self + 0x48) = e70;
    *(char**)(self + 0x54) = e84;
    *(char**)(self + 0x64) = edc;
    *(char**)(self + 0x70) = eec;
    *(char**)(self + 0x7c) = e100;
    *(char**)(self + 0x88) = e118;
    *(char**)(self + 0x90) = e124;
    *(int*)(self + 0x2148) = arg3[13];
    self[0x2150] = 0;
    *(int*)(self + 0x2158) = 0x75;
    *(int*)(self + 0x215c) = 0xf9f;
    *(int*)(self + 0x2160) = 0x5dbf;
    *(int*)(self + 0x2164) = 0;
    *(char**)(self + 0x2154) = lbl_27_data_8E02C;
    *(char**)(self + 0x214c) = lbl_27_data_8E02C + 8;
    *(int*)(self + 0x2168) = arg3[13];
    *(int*)(self + 0x2170) = arg3[13] + 4;
    *(int*)(self + 0x2174) = arg3[13] + 8;

    fn_27_1F980(self + 0x2180);

    pair.b = 0;
    pair.a = lbl_27_bss_7FA4;
    ((Object_vptr_0*)*(char**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70))
        ->slot28(&pair, 2);
    fn_27_1D8FC8(self, 0);
    return self;
}
