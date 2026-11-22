#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3();
    virtual int slot4();
    virtual int slot5();
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
struct Arg2 { int pad; Object_vptr_0* heap; };
struct Build { int data[18]; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_data_13730[], lbl_27_data_86DD8[], lbl_27_data_86DEC[], lbl_27_data_87058[];
extern float lbl_27_rodata_7590, lbl_27_rodata_7594;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_324C34(void*, void*, void*);
void fn_27_2DBBA8(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void* fn_27_324900(char* self, int arg1, Arg2* arg2, const int* arg3) {
    Build build;
    float tbl[15];
    int t22;
    int t23;
    Object_vptr_0* r24 = *(Object_vptr_0**)((char*)arg2 + 4);
    t23 = r24->slot5();
    t22 = r24->slot4();
    int t6 = r24->slot2();
    unsigned char id = *arg3 & 0xff;
    fn_27_1DC5E8(&build, 9, arg3, t6, t22, t23, id, -1,
                 g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_86DD8, build.data[1], build.data[2], arg1, arg2, self + 0x8c4, 1);
    char* sub = self + 0xcc;
    *(char**)(self+0x3c)=lbl_27_data_87058;
    *(char**)(self+0x40)=lbl_27_data_87058+0x64;
    *(char**)(self+0x48)=lbl_27_data_87058+0x70;
    *(char**)(self+0x54)=lbl_27_data_87058+0x84;
    *(char**)(self+0x64)=lbl_27_data_87058+0xdc;
    *(char**)(self+0x70)=lbl_27_data_87058+0xec;
    *(char**)(self+0x7c)=lbl_27_data_87058+0x100;
    *(char**)(self+0x88)=lbl_27_data_87058+0x118;
    *(char**)(self+0x90)=lbl_27_data_87058+0x124;
    fn_27_324C34(sub, self, &build);
    fn_27_2DBBA8(sub+0x1898, sub+0x7f8, &build);
    fn_27_1DBA64(self+0x1f14);

    tbl[12] = lbl_27_rodata_7590;
    tbl[9] = lbl_27_rodata_7594;
    tbl[13] = lbl_27_rodata_7590;
    tbl[14] = lbl_27_rodata_7590;
    tbl[10] = lbl_27_rodata_7594;
    tbl[11] = lbl_27_rodata_7594;
    tbl[6] = lbl_27_rodata_7590;
    tbl[7] = lbl_27_rodata_7590;
    tbl[8] = lbl_27_rodata_7590;
    tbl[3] = lbl_27_rodata_7594;
    tbl[4] = lbl_27_rodata_7594;
    tbl[5] = lbl_27_rodata_7594;
    tbl[0] = lbl_27_rodata_7594;
    tbl[1] = lbl_27_rodata_7594;
    tbl[2] = lbl_27_rodata_7594;
    int* ti = (int*)tbl;

    self[0x1f50]=0;
    ((FlagByte*)(self+0x1f51))->flag = 1;
    self[0x1f52]=0;
    *(char**)(self+0x1f4c)=lbl_27_data_13730;
    *(int*)(self+0x1f54) = ti[0];
    *(int*)(self+0x1f58) = ti[1];
    *(int*)(self+0x1f5c) = ti[2];
    *(int*)(self+0x1f60) = ti[3];
    *(int*)(self+0x1f64) = ti[4];
    *(int*)(self+0x1f68) = ti[5];
    *(int*)(self+0x1f6c) = ti[6];
    *(int*)(self+0x1f70) = ti[7];
    *(int*)(self+0x1f74) = ti[8];
    *(int*)(self+0x1f78) = ti[9];
    *(int*)(self+0x1f7c) = ti[10];
    *(int*)(self+0x1f80) = ti[11];
    *(int*)(self+0x1f84) = ti[12];
    *(int*)(self+0x1f88) = ti[13];
    *(int*)(self+0x1f8c) = ti[14];
    fn_27_1D90FC(self);

    struct ShortSlot { short n; short pad; };
    ShortSlot m;
    ShortSlot n;
    n.n=1;
    ((Class_18ED8*)*(void**)(*(char**)(*(char**)(self+0x60)+0xd8)+0x7c))->slot3(self+0x1f14,0,&n.n,-1);
    m.n=1;
    ((Class_18ED8*)*(void**)(*(char**)(*(char**)(self+0x60)+0xd8)+0x7c))->slot3(self+0x1f4c,1,&m.n,-1);

    *(char**)(self+0x3c)=lbl_27_data_86DEC;
    *(char**)(self+0x40)=lbl_27_data_86DEC+0x64;
    *(char**)(self+0x48)=lbl_27_data_86DEC+0x70;
    *(char**)(self+0x54)=lbl_27_data_86DEC+0x84;
    *(char**)(self+0x64)=lbl_27_data_86DEC+0xdc;
    *(char**)(self+0x70)=lbl_27_data_86DEC+0xec;
    *(char**)(self+0x7c)=lbl_27_data_86DEC+0x100;
    *(char**)(self+0x88)=lbl_27_data_86DEC+0x118;
    *(char**)(self+0x90)=lbl_27_data_86DEC+0x124;
    *(int*)(self+0x1f90)=arg3[13];
    fn_27_1D8FC8(self,0);
    return self;
}