#include <revolution/GX.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on
struct Particle;
struct Input;
typedef Particle* (*First)(Input*);
typedef Particle* (*Next)(Input*, Particle*);
class Class_80465538 {
public:
 virtual void fn_80174718();
 virtual void fn_8017B148();
 virtual First fn_80176004(int);
 virtual Next fn_80176028(int);
 char pad[0xaa];
 unsigned char flag;
};
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
};
struct Data { char pad[0x9c]; unsigned short flags; };
struct Input { char pad[0x24]; Data* data; };
struct Params { char pad[0x58]; float scale; };
struct Particle {
 char pad0[0x30]; float a; char pad1[4]; float b;
 char pad2[0x70]; float x,y,z; char pad3[0x10]; Params* params;
};
extern "C" {
void fn_80174AE8(Class_80465538*, void*);
void fn_80174B58(Class_80465538*, void*, void*);
void fn_80174E38(Class_80465538*, Input*, void*, void*);
void fn_801750E8(Class_80465538*, Particle*, void*, void*, int, int);
void fn_801F1330(int,int,int);
void fn_801EFB10();
void fn_801EF280(int,int);
void fn_801EFB44(int,int,int,int,int);
void fn_801F52E4(int);
void fn_8016DE48(Input*, Mtx);
void fn_801EC1B8(void*,Mtx,Mtx);
void fn_801F51DC(const void*,unsigned int);
extern float lbl_8059E8D0;
extern const float lbl_805A3028;
extern const float lbl_805A302C;
extern float lbl_805A3030;
}
extern "C" void fn_8017B148(Class_80465538* self, void* arg, Input* input) {
 bool tex;
 void* data=&input->data->flags;
 fn_80174AE8(self,data);
 fn_80174B58(self,data,arg);
 fn_80174E38(self,input,data,arg);
 fn_801F1330(0,1,1);
 fn_801EFB10();
 fn_801EF280(9,1);
 if(self->flag) fn_801EF280(13,1);
 fn_801EFB44(0,9,1,4,0);
 fn_801EFB44(0,13,1,4,0);
 fn_801F52E4(0);
 First first;
 unsigned short* fl=&input->data->flags;
 Mtx m1,m2;
 fn_8016DE48(input,m1);
 fn_801EC1B8(arg,m1,m2);
 fn_801F51DC(m2,0);
 Next next;
 int size;
 int initial;
 Particle* p;
 {
 first=self->fn_80176004(*fl & 0x800);
 next=self->fn_80176028(*fl & 0x800);
 size=0;
 initial=1;
 p=first(input);
 }
 while(p) {
 float product=p->a*p->b;
 float value=product*p->params->scale;
 if(!(value<lbl_805A3028)) {
 float* limit=value<lbl_8059E8D0?&value:&lbl_8059E8D0;
 int n=(int)(lbl_805A302C * *limit);
 if((unsigned char)n) {
 if((unsigned char)size!=(unsigned char)n) {
 size=n;
 GXSetPointSize(n,5);
 fn_801750E8(self,p,fl,arg,initial,1);
 } else {
 fn_801750E8(self,p,fl,arg,initial,0);
 }
 tex=self->flag!=0;
 initial=0;
 GXBegin((GXPrimitive)0xb8,(GXVtxFmt)0,1);
 GXPosition3f32(p->x,p->y,p->z);
 if(tex) { WGPIPE.f=lbl_805A3030; WGPIPE.f=lbl_805A3030; }
 }
 }
 p=next(input,p);
 }
}
