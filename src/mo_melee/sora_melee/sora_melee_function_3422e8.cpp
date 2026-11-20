#include <types.h>
#pragma force_active on

class Class_CF8 {
public:
    virtual void fn_27_1000C();
    virtual void fn_27_100D0();
    virtual int fn_27_100CC();
    virtual void fn_27_10094();
    virtual int fn_27_100C8();
    virtual int fn_27_100C4();
};

class Class_18ED8 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void*, int, short*, int);
    virtual void slot4();
    virtual void slot5();
};

struct Input { int pad; Class_CF8* node; };
struct Build { int data[18]; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
struct ShortSlot { short n; short pad; };

extern "C" {
extern char lbl_27_data_13730[];
extern char lbl_27_data_8C4C0[];
extern char lbl_27_data_8C4D4[];
extern char lbl_27_data_8C740[];
extern char lbl_27_data_8C9AC[];
extern float lbl_27_rodata_7880;
extern float lbl_27_rodata_7884;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_342F1C(void*, void*, void*);
void fn_27_343FD4(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void* fn_27_3422E8(char* self, int arg1, Input* arg2, const int* arg3) {
    Build build;
    float tbl[15];
    ShortSlot m;
    ShortSlot n;
    int t22;
    int t23;

    Class_CF8* r24 = arg2->node;
    t23 = r24->fn_27_100C4();
    t22 = r24->fn_27_100C8();
    int t6 = r24->fn_27_100CC();
    unsigned char id = *arg3 & 0xff;
    fn_27_1DC5E8(&build, 0x45, arg3, t6, t22, t23, id, -1, self + 0x17c8, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_8C4C0, build.data[1], build.data[2], arg1, arg2, self + 0x5c4, 1);

    char* sub = self + 0xcc;
    *(char**)(self + 0x3c) = lbl_27_data_8C740;
    *(char**)(self + 0x40) = lbl_27_data_8C740 + 0x64;
    *(char**)(self + 0x48) = lbl_27_data_8C740 + 0x70;
    *(char**)(self + 0x54) = lbl_27_data_8C740 + 0x84;
    *(char**)(self + 0x64) = lbl_27_data_8C740 + 0xdc;
    *(char**)(self + 0x70) = lbl_27_data_8C740 + 0xec;
    *(char**)(self + 0x7c) = lbl_27_data_8C740 + 0x100;
    *(char**)(self + 0x88) = lbl_27_data_8C740 + 0x118;
    *(char**)(self + 0x90) = lbl_27_data_8C740 + 0x124;

    fn_27_342F1C(sub, self, &build);
    fn_27_343FD4(sub + 0x1324, sub + 0x4f8, &build);
    fn_27_1DBA64(self + 0x1748);

    float fNeg = lbl_27_rodata_7880;
    tbl[9] = lbl_27_rodata_7884;
    tbl[12] = fNeg;
    tbl[13] = fNeg;
    tbl[14] = fNeg;
    tbl[10] = lbl_27_rodata_7884;
    tbl[11] = lbl_27_rodata_7884;
    tbl[6] = fNeg;
    tbl[7] = fNeg;
    tbl[8] = fNeg;
    tbl[3] = lbl_27_rodata_7884;
    tbl[4] = lbl_27_rodata_7884;
    tbl[5] = lbl_27_rodata_7884;
    tbl[0] = lbl_27_rodata_7884;
    tbl[1] = lbl_27_rodata_7884;
    tbl[2] = lbl_27_rodata_7884;
    int* ti = (int*)tbl;

    self[0x1784] = 0;
    ((FlagByte*)(self + 0x1785))->flag = 1;
    self[0x1786] = 0;
    *(char**)(self + 0x1780) = lbl_27_data_13730;
    *(int*)(self + 0x1788) = ti[0];
    *(int*)(self + 0x178c) = ti[1];
    *(int*)(self + 0x1790) = ti[2];
    *(int*)(self + 0x1794) = ti[3];
    *(int*)(self + 0x1798) = ti[4];
    *(int*)(self + 0x179c) = ti[5];
    *(int*)(self + 0x17a0) = ti[6];
    *(int*)(self + 0x17a4) = ti[7];
    *(int*)(self + 0x17a8) = ti[8];
    *(int*)(self + 0x17ac) = ti[9];
    *(int*)(self + 0x17b0) = ti[10];
    *(int*)(self + 0x17b4) = ti[11];
    *(int*)(self + 0x17b8) = ti[12];
    *(int*)(self + 0x17bc) = ti[13];
    *(int*)(self + 0x17c0) = ti[14];
    fn_27_1D90FC(self);

    n.n = 1;
    ((Class_18ED8*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))->slot3(self + 0x1748, 0, &n.n, -1);
    m.n = 1;
    ((Class_18ED8*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))->slot3(self + 0x1780, 1, &m.n, -1);

    *(char**)(self + 0x3c) = lbl_27_data_8C4D4;
    *(char**)(self + 0x40) = lbl_27_data_8C4D4 + 0x64;
    *(char**)(self + 0x48) = lbl_27_data_8C4D4 + 0x70;
    *(char**)(self + 0x54) = lbl_27_data_8C4D4 + 0x84;
    *(char**)(self + 0x64) = lbl_27_data_8C4D4 + 0xdc;
    *(char**)(self + 0x70) = lbl_27_data_8C4D4 + 0xec;
    *(char**)(self + 0x7c) = lbl_27_data_8C4D4 + 0x100;
    *(char**)(self + 0x88) = lbl_27_data_8C4D4 + 0x118;
    *(char**)(self + 0x90) = lbl_27_data_8C4D4 + 0x124;
    *(int*)(self + 0x17c4) = arg3[13];
    self[0x17cc] = 0;
    *(int*)(self + 0x17d4) = 0x45;
    *(int*)(self + 0x17d8) = 0xf9f;
    *(int*)(self + 0x17dc) = 0x5dbf;
    *(int*)(self + 0x17e0) = 0;
    *(char**)(self + 0x17d0) = lbl_27_data_8C9AC;
    *(char**)(self + 0x17c8) = lbl_27_data_8C9AC + 8;
    *(int*)(self + 0x17e4) = arg3[13];
    fn_27_1D8FC8(self, 0);
    return self;
}
