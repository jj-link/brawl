#pragma force_active on
#include <gm/gm_global.h>
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(float); virtual void slot9(); virtual void slot10();
virtual void slot11(int,int); virtual void slot12(); virtual void slot13(int);
char pad[0xE0]; int value;
};
struct Frame { char pad[8]; Object_vptr_0* animation; };
struct Child { char pad[0x10]; int handle; Frame* frame; };
struct Object { char pad[0xC4]; Child* child; char pad1[0x2B0-0xC8]; int mode; };
extern const double lbl_805A23B8;
extern "C" {
extern Object_vptr_0* lbl_805A02E0;
extern float lbl_805A23B0, lbl_805A23C0, lbl_805A244C, lbl_805A2454, lbl_805A2458;
extern float lbl_804088A0[], lbl_804088B0[];
void fn_800B6F6C(void*,const float*);
void fn_800B6838(void*,const float*,float,float,float,float);
void fn_800E4FD0(Object* self,int arg1,int arg2) {
float stack[6];
Child* child=self->child;
int mode=self->mode;
lbl_805A02E0->slot13(child->handle);
if(mode!=0) {
float scale;
if(mode==1) scale=lbl_805A23B0; else scale=lbl_805A244C;
stack[0]=lbl_805A23B0; stack[1]=lbl_805A23B0; stack[2]=scale;
fn_800B6F6C(child,&stack[0]);
unsigned char flag=((unsigned char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28];
float* values=((flag>>7)&1)?lbl_804088B0:lbl_804088A0;
float base;
if(mode==1) base=values[0]; else base=values[1];
stack[3]=base;
float spacing;
if(arg2>1) spacing=lbl_805A2454*(float)(arg2-1); else spacing=lbl_805A23B0;
float index=(float)arg1;
float sum=values[2]+values[3];
float end=sum*lbl_805A2458;
float offset=end-spacing*lbl_805A2458;
stack[4]=offset+lbl_805A2454*index;
stack[5]=lbl_805A23B0;
fn_800B6838(child,&stack[3],lbl_805A2454,index,offset,end);
lbl_805A02E0->slot11(lbl_805A02E0->value,child->handle);
child->frame->animation->slot8(lbl_805A23C0);
}
}
}