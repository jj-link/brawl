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
class Getter {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual short get();
};
class Observer {
public:
    virtual void addObserver(short, signed char);
    short id;
    short type;
    short link;
};
struct Modules {
    char pad[0x7c];
    Class_18ED8* event;
    Getter* getter;
};
struct Access {
    char pad[0xd8];
    Modules* modules;
};
struct Arg2 { int pad; Object_vptr_0* heap; };
struct Build { int data[18]; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

extern "C" {
extern char lbl_27_data_A16B8[], lbl_27_data_A16C8[], lbl_27_data_A19F8[];
extern char lbl_27_data_13730[], lbl_27_data_29B58[], lbl_27_data_A1D28[];
extern float lbl_27_rodata_8020, lbl_27_rodata_8024;
void fn_27_1DC5E8(void*, int, const void*, int, int, int, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, int, int, int, void*, void*, int);
void fn_27_3B9918(void*, void*, void*);
void fn_27_32099C(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}

extern "C" void* fn_27_3B92A0(char* self, int arg1, Arg2* arg2, const int* arg3) {
    Build build;
    float tbl[15];
    int t22;
    Object_vptr_0* obj = *(Object_vptr_0**)((char*)arg2 + 4);
    t22 = obj->slot5();
    int t6 = obj->slot2();
    unsigned char id = *arg3 & 0xff;
    fn_27_1DC5E8(&build, 0x87, arg3, t6, 0x1f, t22, id, -1,
                 self + 0x1f24, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_A16B8, build.data[1], build.data[2], arg1, arg2,
                 self + 0x8c4, 1);
    char* sub = self + 0xcc;
    *(char**)(self+0x3c)=lbl_27_data_A19F8;
    *(char**)(self+0x40)=lbl_27_data_A19F8+0x64;
    *(char**)(self+0x48)=lbl_27_data_A19F8+0x70;
    *(char**)(self+0x54)=lbl_27_data_A19F8+0x84;
    *(char**)(self+0x64)=lbl_27_data_A19F8+0xdc;
    *(char**)(self+0x70)=lbl_27_data_A19F8+0xec;
    *(char**)(self+0x7c)=lbl_27_data_A19F8+0x100;
    *(char**)(self+0x88)=lbl_27_data_A19F8+0x118;
    *(char**)(self+0x90)=lbl_27_data_A19F8+0x124;
    fn_27_3B9918(sub, self, &build);
    fn_27_32099C(sub+0x181c, sub+0x7f8, &build);
    fn_27_1DBA64(self+0x1e98);

    tbl[12] = lbl_27_rodata_8020;
    tbl[9] = lbl_27_rodata_8024;
    tbl[13] = lbl_27_rodata_8020;
    tbl[14] = lbl_27_rodata_8020;
    tbl[10] = lbl_27_rodata_8024;
    tbl[11] = lbl_27_rodata_8024;
    tbl[6] = lbl_27_rodata_8020;
    tbl[7] = lbl_27_rodata_8020;
    tbl[8] = lbl_27_rodata_8020;
    tbl[3] = lbl_27_rodata_8024;
    tbl[4] = lbl_27_rodata_8024;
    tbl[5] = lbl_27_rodata_8024;
    tbl[0] = lbl_27_rodata_8024;
    tbl[1] = lbl_27_rodata_8024;
    tbl[2] = lbl_27_rodata_8024;
    int* ti = (int*)tbl;

    self[0x1ed4]=0;
    ((FlagByte*)(self+0x1ed5))->flag = 1;
    self[0x1ed6]=0;
    *(char**)(self+0x1ed0)=lbl_27_data_13730;
    *(int*)(self+0x1ed8) = ti[0];
    *(int*)(self+0x1edc) = ti[1];
    *(int*)(self+0x1ee0) = ti[2];
    *(int*)(self+0x1ee4) = ti[3];
    *(int*)(self+0x1ee8) = ti[4];
    *(int*)(self+0x1eec) = ti[5];
    *(int*)(self+0x1ef0) = ti[6];
    *(int*)(self+0x1ef4) = ti[7];
    *(int*)(self+0x1ef8) = ti[8];
    *(int*)(self+0x1efc) = ti[9];
    *(int*)(self+0x1f00) = ti[10];
    *(int*)(self+0x1f04) = ti[11];
    *(int*)(self+0x1f08) = ti[12];
    *(int*)(self+0x1f0c) = ti[13];
    *(int*)(self+0x1f10) = ti[14];
    fn_27_1D90FC(self);

    struct ShortSlot { short n; short pad; };
    ShortSlot m;
    ShortSlot n;
    n.n=1;
    ((Access*)*(void**)(self+0x60))->modules->event->slot3(self+0x1e98,0,&n.n,-1);
    m.n=1;
    ((Access*)*(void**)(self+0x60))->modules->event->slot3(self+0x1ed0,1,&m.n,-1);

    char* gp = (char*)((Access*)*(void**)(self+0x60))->modules->getter;
    short taskId = ((Getter*)(gp + 8))->get();
    Observer* ob = (Observer*)(self+0x1f14);
    ob->id = -1;
    ob->type = 10;
    ob->link = -1;
    *(char**)(self+0x1f14) = lbl_27_data_29B58;
    ob->addObserver(taskId, -1);

    char* e = lbl_27_data_A16C8;
    *(char**)(self+0x3c)=e;
    *(char**)(self+0x40)=e+0x64;
    *(char**)(self+0x48)=e+0x70;
    *(char**)(self+0x54)=e+0x84;
    *(char**)(self+0x64)=e+0xdc;
    *(char**)(self+0x70)=e+0xec;
    *(char**)(self+0x7c)=e+0x100;
    *(char**)(self+0x88)=e+0x118;
    *(char**)(self+0x90)=e+0x124;
    *(char**)(self+0x1f14)=e+0x26c;
    *(int*)(self+0x1f20)=arg3[13];
    self[0x1f28]=0;
    *(int*)(self+0x1f30)=0x87;
    *(int*)(self+0x1f34)=0xf9f;
    *(int*)(self+0x1f38)=0x5dbf;
    *(int*)(self+0x1f3c)=0;
    char* f = lbl_27_data_A1D28;
    *(char**)(self+0x1f2c)=f;
    *(char**)(self+0x1f24)=f+8;
    *(int*)(self+0x1f40)=arg3[13];
    *(int*)(self+0x1f44)=arg3[13]+4;
    *(int*)(self+0x1f48)=arg3[13]+8;
    fn_27_1D8FC8(self,0);
    return self;
}
