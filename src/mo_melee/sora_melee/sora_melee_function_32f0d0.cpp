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
};
struct Arg2 { int pad; Object_vptr_0* heap; };
struct Build { int data[18]; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_data_13730[], lbl_27_data_88AF8[], lbl_27_data_88B04[], lbl_27_data_88D70[];
extern float lbl_27_rodata_7658, lbl_27_rodata_765C;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_32F6A8(void*, void*, void*);
void fn_27_2DBBA8(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void* fn_27_32F0D0(char* self, int arg1, Arg2* arg2, const int* arg3) {
    Build build;
    float tbl[15];
    int t22;
    int t23;
    Object_vptr_0* r24 = *(Object_vptr_0**)((char*)arg2 + 4);
    t23 = r24->slot5();
    t22 = r24->slot4();
    int t6 = r24->slot2();
    unsigned char id = *arg3 & 0xff;
    fn_27_1DC5E8(&build, 0x73, arg3, t6, t22, t23, id, -1,
                 g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_88AF8, build.data[1], build.data[2], arg1, arg2, self + 0x8c4, 1);
    char* sub = self + 0xcc;
    *(char**)(self+0x3c)=lbl_27_data_88D70;
    *(char**)(self+0x40)=lbl_27_data_88D70+0x64;
    *(char**)(self+0x48)=lbl_27_data_88D70+0x70;
    *(char**)(self+0x54)=lbl_27_data_88D70+0x84;
    *(char**)(self+0x64)=lbl_27_data_88D70+0xdc;
    *(char**)(self+0x70)=lbl_27_data_88D70+0xec;
    *(char**)(self+0x7c)=lbl_27_data_88D70+0x100;
    *(char**)(self+0x88)=lbl_27_data_88D70+0x118;
    *(char**)(self+0x90)=lbl_27_data_88D70+0x124;
    fn_27_32F6A8(sub, self, &build);
    fn_27_2DBBA8(sub+0x1884, sub+0x7f8, &build);
    fn_27_1DBA64(self+0x1f00);

    tbl[12] = lbl_27_rodata_7658;
    tbl[9] = lbl_27_rodata_765C;
    tbl[13] = lbl_27_rodata_7658;
    tbl[14] = lbl_27_rodata_7658;
    tbl[10] = lbl_27_rodata_765C;
    tbl[11] = lbl_27_rodata_765C;
    tbl[6] = lbl_27_rodata_7658;
    tbl[7] = lbl_27_rodata_7658;
    tbl[8] = lbl_27_rodata_7658;
    tbl[3] = lbl_27_rodata_765C;
    tbl[4] = lbl_27_rodata_765C;
    tbl[5] = lbl_27_rodata_765C;
    tbl[0] = lbl_27_rodata_765C;
    tbl[1] = lbl_27_rodata_765C;
    tbl[2] = lbl_27_rodata_765C;
    int* ti = (int*)tbl;

    self[0x1f3c]=0;
    ((FlagByte*)(self+0x1f3d))->flag = 1;
    self[0x1f3e]=0;
    *(char**)(self+0x1f38)=lbl_27_data_13730;
    *(int*)(self+0x1f40) = ti[0];
    *(int*)(self+0x1f44) = ti[1];
    *(int*)(self+0x1f48) = ti[2];
    *(int*)(self+0x1f4c) = ti[3];
    *(int*)(self+0x1f50) = ti[4];
    *(int*)(self+0x1f54) = ti[5];
    *(int*)(self+0x1f58) = ti[6];
    *(int*)(self+0x1f5c) = ti[7];
    *(int*)(self+0x1f60) = ti[8];
    *(int*)(self+0x1f64) = ti[9];
    *(int*)(self+0x1f68) = ti[10];
    *(int*)(self+0x1f6c) = ti[11];
    *(int*)(self+0x1f70) = ti[12];
    *(int*)(self+0x1f74) = ti[13];
    *(int*)(self+0x1f78) = ti[14];
    fn_27_1D90FC(self);

    struct ShortSlot { short n; short pad; };
    ShortSlot m;
    ShortSlot n;
    n.n=1;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self+0x60)+0xd8)+0x7c))->slot3(self+0x1f00,0,&n.n,-1);
    m.n=1;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self+0x60)+0xd8)+0x7c))->slot3(self+0x1f38,1,&m.n,-1);

    *(char**)(self+0x3c)=lbl_27_data_88B04;
    *(char**)(self+0x40)=lbl_27_data_88B04+0x64;
    *(char**)(self+0x48)=lbl_27_data_88B04+0x70;
    *(char**)(self+0x54)=lbl_27_data_88B04+0x84;
    *(char**)(self+0x64)=lbl_27_data_88B04+0xdc;
    *(char**)(self+0x70)=lbl_27_data_88B04+0xec;
    *(char**)(self+0x7c)=lbl_27_data_88B04+0x100;
    *(char**)(self+0x88)=lbl_27_data_88B04+0x118;
    *(char**)(self+0x90)=lbl_27_data_88B04+0x124;
    *(int*)(self+0x1f7c)=arg3[13];
    fn_27_1D8FC8(self,0);
    return self;
}