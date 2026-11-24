#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3(void*, int, short*, int);
    virtual void slot4();
    virtual void* slot5();
};
extern "C" {
void fn_27_1DC5E8(void*, int, const void*, void*, int, void*, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, u32, u32, int, void*, void*, int);
void fn_27_3B6C84(void*, void*, void*);
void fn_27_3B77E4(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
extern char lbl_27_data_13730[];
extern char lbl_27_data_A0FF8[];
extern char lbl_27_data_A1004[];
extern char lbl_27_data_A1318[];
extern char lbl_27_data_A1650[];
extern float lbl_27_rodata_8010, lbl_27_rodata_8014;
}
struct Vec { float x,y,z; };
struct WordVec { int x,y,z; };
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };
struct Desc { int a,b,c; char rest[0x34]; double align; };
struct Arg2 { int x; Object_vptr_0* obj; };
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define V(p,o) (*(WordVec*)((char*)(p)+(o)))

extern "C" void* fn_27_3B6680(char* self, int arg1, Arg2* arg2, const int* arg3) {
 Desc desc;
 struct ShortSlot { short value; short pad; } s1, s0;
 void* a;
 Object_vptr_0* obj = arg2->obj;
 a = obj->slot5();
 void* b = obj->slot2();
 unsigned char id = *arg3 & 0xff;
 fn_27_1DC5E8(&desc, 0x86, arg3, b, 0x1f, a, id, -1, self + 0x1efc, 0,0,0,0,0,0,0);
 fn_27_1D7EF0(self, lbl_27_data_A0FF8, desc.b, desc.c, arg1, arg2, self+0x8c4, 1);
 char* p = self + 0xcc;
 P(self,0x3c)=lbl_27_data_A1318;
 P(self,0x40)=lbl_27_data_A1318+0x64;
 P(self,0x48)=lbl_27_data_A1318+0x70;
 P(self,0x54)=lbl_27_data_A1318+0x84;
 P(self,0x64)=lbl_27_data_A1318+0xdc;
 P(self,0x70)=lbl_27_data_A1318+0xec;
 P(self,0x7c)=lbl_27_data_A1318+0x100;
 P(self,0x88)=lbl_27_data_A1318+0x118;
 P(self,0x90)=lbl_27_data_A1318+0x124;
 fn_27_3B6C84(p,self,&desc);
 fn_27_3B77E4(p+0x1800,p+0x7f8,&desc);
 fn_27_1DBA64(self+0x1e7c);
 Vec v4 = {lbl_27_rodata_8010,lbl_27_rodata_8010,lbl_27_rodata_8010};
 Vec v3 = {lbl_27_rodata_8014,lbl_27_rodata_8014,lbl_27_rodata_8014};
 Vec v2 = {lbl_27_rodata_8010,lbl_27_rodata_8010,lbl_27_rodata_8010};
 Vec v1 = {lbl_27_rodata_8014,lbl_27_rodata_8014,lbl_27_rodata_8014};
 Vec v0 = {lbl_27_rodata_8014,lbl_27_rodata_8014,lbl_27_rodata_8014};
 B(self,0x1eb8)=0;
 ((FlagByte*)(self+0x1eb9))->flag = 1;
 B(self,0x1eba)=0;
 P(self,0x1eb4)=lbl_27_data_13730;
 V(self,0x1ebc)=*(WordVec*)&v0;
 V(self,0x1ec8)=*(WordVec*)&v1;
 V(self,0x1ed4)=*(WordVec*)&v2;
 V(self,0x1ee0)=*(WordVec*)&v3;
 V(self,0x1eec)=*(WordVec*)&v4;
 fn_27_1D90FC(self);
 s0.value=1;
 ((Object_vptr_0*)P(P(P(self,0x60),0xd8),0x7c))->slot3(self+0x1e7c,0,&s0.value,-1);
 s1.value=1;
 ((Object_vptr_0*)P(P(P(self,0x60),0xd8),0x7c))->slot3(self+0x1eb4,1,&s1.value,-1);
 P(self,0x3c)=lbl_27_data_A1004;
 P(self,0x40)=lbl_27_data_A1004+0x64;
 P(self,0x48)=lbl_27_data_A1004+0x70;
 P(self,0x54)=lbl_27_data_A1004+0x84;
 P(self,0x64)=lbl_27_data_A1004+0xdc;
 P(self,0x70)=lbl_27_data_A1004+0xec;
 P(self,0x7c)=lbl_27_data_A1004+0x100;
 P(self,0x88)=lbl_27_data_A1004+0x118;
 P(self,0x90)=lbl_27_data_A1004+0x124;
 W(self,0x1ef8)=arg3[13];
 B(self,0x1f00)=0;
 W(self,0x1f08)=0x86;
 W(self,0x1f0c)=0xf9f;
 W(self,0x1f10)=0x5dbf;
 W(self,0x1f14)=0;
 P(self,0x1f04)=lbl_27_data_A1650;
 P(self,0x1efc)=lbl_27_data_A1650+8;
 W(self,0x1f18)=arg3[13];
 fn_27_1D8FC8(self,0);
 return self;
}