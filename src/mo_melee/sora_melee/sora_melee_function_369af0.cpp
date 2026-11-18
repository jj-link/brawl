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
extern char lbl_27_data_13730[], lbl_27_data_92200[], lbl_27_data_9221C[], lbl_27_data_92488[];
extern float lbl_27_rodata_7B40, lbl_27_rodata_7B44;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_36A664(void*, void*, void*);
void fn_27_36BA88(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void* fn_27_369AF0(char* self, int arg1, Arg2* arg2, const int* arg3) {
    Build build;
    float tbl[15];
    int t22;
    int t23;
    Object_vptr_0* r24 = *(Object_vptr_0**)((char*)arg2 + 4);
    t23 = r24->slot5();
    t22 = r24->slot4();
    int t6 = r24->slot2();
    unsigned char id = *arg3 & 0xff;
    fn_27_1DC5E8(&build, 13, arg3, t6, t22, t23, id, -1,
                 g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_92200, build.data[1], build.data[2], arg1, arg2, self + 0x538, 1);
    char* sub = self + 0xcc;
    *(char**)(self+0x3c)=lbl_27_data_92488;
    *(char**)(self+0x40)=lbl_27_data_92488+0x64;
    *(char**)(self+0x48)=lbl_27_data_92488+0x70;
    *(char**)(self+0x54)=lbl_27_data_92488+0x84;
    *(char**)(self+0x64)=lbl_27_data_92488+0xdc;
    *(char**)(self+0x70)=lbl_27_data_92488+0xec;
    *(char**)(self+0x7c)=lbl_27_data_92488+0x100;
    *(char**)(self+0x88)=lbl_27_data_92488+0x118;
    *(char**)(self+0x90)=lbl_27_data_92488+0x124;
    fn_27_36A664(sub, self, &build);
    fn_27_36BA88(sub+0x11dc, sub+0x46c, &build);
    fn_27_1DBA64(self+0x15cc);

    tbl[12] = lbl_27_rodata_7B40;
    tbl[9] = lbl_27_rodata_7B44;
    tbl[13] = lbl_27_rodata_7B40;
    tbl[14] = lbl_27_rodata_7B40;
    tbl[10] = lbl_27_rodata_7B44;
    tbl[11] = lbl_27_rodata_7B44;
    tbl[6] = lbl_27_rodata_7B40;
    tbl[7] = lbl_27_rodata_7B40;
    tbl[8] = lbl_27_rodata_7B40;
    tbl[3] = lbl_27_rodata_7B44;
    tbl[4] = lbl_27_rodata_7B44;
    tbl[5] = lbl_27_rodata_7B44;
    tbl[0] = lbl_27_rodata_7B44;
    tbl[1] = lbl_27_rodata_7B44;
    tbl[2] = lbl_27_rodata_7B44;
    int* ti = (int*)tbl;

    self[0x1608]=0;
    ((FlagByte*)(self+0x1609))->flag = 1;
    self[0x160a]=0;
    *(char**)(self+0x1604)=lbl_27_data_13730;
    *(int*)(self+0x160c) = ti[0];
    *(int*)(self+0x1610) = ti[1];
    *(int*)(self+0x1614) = ti[2];
    *(int*)(self+0x1618) = ti[3];
    *(int*)(self+0x161c) = ti[4];
    *(int*)(self+0x1620) = ti[5];
    *(int*)(self+0x1624) = ti[6];
    *(int*)(self+0x1628) = ti[7];
    *(int*)(self+0x162c) = ti[8];
    *(int*)(self+0x1630) = ti[9];
    *(int*)(self+0x1634) = ti[10];
    *(int*)(self+0x1638) = ti[11];
    *(int*)(self+0x163c) = ti[12];
    *(int*)(self+0x1640) = ti[13];
    *(int*)(self+0x1644) = ti[14];
    fn_27_1D90FC(self);

    struct ShortSlot { short n; short pad; };
    ShortSlot m;
    ShortSlot n;
    n.n=1;
    ((Class_18ED8*)*(void**)(*(char**)(*(char**)(self+0x60)+0xd8)+0x7c))->slot3(self+0x15cc,0,&n.n,-1);
    m.n=1;
    ((Class_18ED8*)*(void**)(*(char**)(*(char**)(self+0x60)+0xd8)+0x7c))->slot3(self+0x1604,1,&m.n,-1);

    *(char**)(self+0x3c)=lbl_27_data_9221C;
    *(char**)(self+0x40)=lbl_27_data_9221C+0x64;
    *(char**)(self+0x48)=lbl_27_data_9221C+0x70;
    *(char**)(self+0x54)=lbl_27_data_9221C+0x84;
    *(char**)(self+0x64)=lbl_27_data_9221C+0xdc;
    *(char**)(self+0x70)=lbl_27_data_9221C+0xec;
    *(char**)(self+0x7c)=lbl_27_data_9221C+0x100;
    *(char**)(self+0x88)=lbl_27_data_9221C+0x118;
    *(char**)(self+0x90)=lbl_27_data_9221C+0x124;
    *(int*)(self+0x1648)=arg3[13];
    fn_27_1D8FC8(self,0);
    return self;
}
