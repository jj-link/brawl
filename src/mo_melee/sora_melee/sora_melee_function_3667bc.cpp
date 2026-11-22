#include <types.h>
#include <so/so_value_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
    virtual void slot3(void*, int, short*, int);
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
    virtual void slot28(void**, int);
};
struct Arg2 { int pad; Object_vptr_0* heap; };
struct Build { int data[14]; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
struct ShortSlot { short n; short pad; };

extern "C" {
extern char lbl_27_data_13730[], lbl_27_data_918A0[], lbl_27_data_918B4[], lbl_27_data_91BC8[];
extern char lbl_27_bss_82C4[];
extern float lbl_27_rodata_7B10, lbl_27_rodata_7B14;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_366B0C(void*, void*, void*);
void fn_27_3097BC(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void* fn_27_3667BC(char* self, int arg1, Arg2* arg2, const int* arg3) {
    Build build;
    float tbl[15];
    void* process[2];
    ShortSlot m;
    ShortSlot n;
    int t22;
    int t23;

    Object_vptr_0* r24 = *(Object_vptr_0**)((char*)arg2 + 4);
    t23 = r24->slot5();
    int t6 = r24->slot2();
    unsigned char id = *arg3 & 0xff;
    fn_27_1DC5E8(&build, 0x38, arg3, t6, 0x1f, t23, id, -1,
                 &g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_918A0, build.data[1], build.data[2], arg1, arg2,
                 self + 0x8c4, 1);

    char* sub = self + 0xcc;
    *(char**)(self + 0x3c) = lbl_27_data_91BC8;
    *(char**)(self + 0x40) = lbl_27_data_91BC8 + 0x64;
    *(char**)(self + 0x48) = lbl_27_data_91BC8 + 0x70;
    *(char**)(self + 0x54) = lbl_27_data_91BC8 + 0x84;
    *(char**)(self + 0x64) = lbl_27_data_91BC8 + 0xdc;
    *(char**)(self + 0x70) = lbl_27_data_91BC8 + 0xec;
    *(char**)(self + 0x7c) = lbl_27_data_91BC8 + 0x100;
    *(char**)(self + 0x88) = lbl_27_data_91BC8 + 0x118;
    *(char**)(self + 0x90) = lbl_27_data_91BC8 + 0x124;
    fn_27_366B0C(sub, self, &build);
    fn_27_3097BC(sub + 0x18b8, sub + 0x7f8, &build);
    fn_27_1DBA64(self + 0x1f34);

    tbl[12] = lbl_27_rodata_7B10;
    tbl[9] = lbl_27_rodata_7B14;
    tbl[13] = lbl_27_rodata_7B10;
    tbl[14] = lbl_27_rodata_7B10;
    tbl[10] = lbl_27_rodata_7B14;
    tbl[11] = lbl_27_rodata_7B14;
    tbl[6] = lbl_27_rodata_7B10;
    tbl[7] = lbl_27_rodata_7B10;
    tbl[8] = lbl_27_rodata_7B10;
    tbl[3] = lbl_27_rodata_7B14;
    tbl[4] = lbl_27_rodata_7B14;
    tbl[5] = lbl_27_rodata_7B14;
    tbl[0] = lbl_27_rodata_7B14;
    tbl[1] = lbl_27_rodata_7B14;
    tbl[2] = lbl_27_rodata_7B14;
    int* ti = (int*)tbl;

    self[0x1f70] = 0;
    ((FlagByte*)(self + 0x1f71))->flag = 1;
    self[0x1f72] = 0;
    *(char**)(self + 0x1f6c) = lbl_27_data_13730;
    *(int*)(self + 0x1f74) = ti[0];
    *(int*)(self + 0x1f78) = ti[1];
    *(int*)(self + 0x1f7c) = ti[2];
    *(int*)(self + 0x1f80) = ti[3];
    *(int*)(self + 0x1f84) = ti[4];
    *(int*)(self + 0x1f88) = ti[5];
    *(int*)(self + 0x1f8c) = ti[6];
    *(int*)(self + 0x1f90) = ti[7];
    *(int*)(self + 0x1f94) = ti[8];
    *(int*)(self + 0x1f98) = ti[9];
    *(int*)(self + 0x1f9c) = ti[10];
    *(int*)(self + 0x1fa0) = ti[11];
    *(int*)(self + 0x1fa4) = ti[12];
    *(int*)(self + 0x1fa8) = ti[13];
    *(int*)(self + 0x1fac) = ti[14];
    fn_27_1D90FC(self);

    n.n = 1;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))
        ->slot3(self + 0x1f34, 0, &n.n, -1);
    m.n = 1;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x7c))
        ->slot3(self + 0x1f6c, 1, &m.n, -1);

    char* s = lbl_27_data_918B4;
    *(char**)(self + 0x3c) = s;
    *(char**)(self + 0x40) = s + 0x64;
    *(char**)(self + 0x48) = s + 0x70;
    *(char**)(self + 0x54) = s + 0x84;
    *(char**)(self + 0x64) = s + 0xdc;
    *(char**)(self + 0x70) = s + 0xec;
    *(char**)(self + 0x7c) = s + 0x100;
    *(char**)(self + 0x88) = s + 0x118;
    *(char**)(self + 0x90) = s + 0x124;
    *(int*)(self + 0x1fb0) = arg3[13];
    process[0] = lbl_27_bss_82C4;
    process[1] = lbl_27_bss_82C4;
    ((Object_vptr_0*)*(void**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x70))
        ->slot28(process, 2);
    fn_27_1D8FC8(self, 0);
    return self;
}