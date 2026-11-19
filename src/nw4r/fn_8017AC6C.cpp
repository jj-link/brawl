#include <nw4r/math/math_types.h>
#include <revolution/GX.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on
using namespace nw4r::math;
extern "C" {
void fn_80174AE8(void*,void*);
void fn_80174B58(void*,void*,void*);
void fn_80174E38(void*,void*,void*,void*);
void fn_801F1330(int,int,int);
void fn_801EFB10();
void fn_801EF280(int,int);
void fn_801EFB44(int,int,int,int,int);
void fn_801F52E4(int);
void fn_8016DE48(void*,void*,void*);
void fn_801EC1B8(void*,void*,void*);
void fn_801F51DC(void*,unsigned int);
float fn_801622A0(float);
void fn_801750E8(void*,void*,void*,void*,int,int);
extern const float lbl_8059E8C8,lbl_805A3018,lbl_805A3024;
extern float lbl_805A301C,lbl_805A3020;
}
struct LinkData { unsigned short flags; };
struct ShapeData { char pad[0x9c]; LinkData link; };
struct Container { char pad[0x24]; ShapeData* data; };
struct Node {
 char pad[0x30]; float a,b,c,d; char pad40[0x6c];
 VEC3 first,second; char padC4[4]; void* material;
};
struct VectorBits { unsigned int x,y,z; };
typedef Node* (*NextFunc)(void*);
typedef Node* (*StepFunc)(void*,Node*);
class Class_80465520 {
public:
 virtual void fn_801746D8();
 virtual void fn_8017AC6C();
 virtual NextFunc fn_80176004(int);
 virtual StepFunc fn_80176028(int);
};
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
};
inline float vectorRoot(float lengthSq, float zero) {
 if(lengthSq<=zero) return zero;
 return lengthSq*fn_801622A0(lengthSq);
}
inline VEC3& divideVector(VEC3& vector, float length, float one) {
 return vector *= (one / length);
}
inline bool normalizeVector(VEC3* vector,float epsilon,float zero,float one) {
 float lengthSq=VEC3Dot(vector,vector);
 if(lengthSq<epsilon) return false;
 divideVector(*vector,vectorRoot(lengthSq,zero),one);
 return true;
}
extern "C" void fn_8017AC6C(void* arg0,void* arg1,Container* arg2) {
 bool hasColor;
 float radius;
 {
 void* data=&arg2->data->link;
 fn_80174AE8(arg0,data);
 fn_80174B58(arg0,data,arg1);
 fn_80174E38(arg0,arg2,data,arg1);
 }
 fn_801F1330(0,1,1);
 fn_801EFB10();
 fn_801EF280(9,1);
 if(*(unsigned char*)((char*)arg0+0xae)) fn_801EF280(13,1);
 fn_801EFB44(0,9,1,4,0);
 fn_801EFB44(0,13,1,4,0);
 fn_801F52E4(0);
 unsigned char sp60[0x30],sp30[0x30];
 LinkData* link=&arg2->data->link;
 fn_8016DE48(arg2,sp60,arg2->data);
 fn_801EC1B8(arg1,sp60,sp30);
 fn_801F51DC(sp30,0);
 Class_80465520* self=(Class_80465520*)arg0;
 NextFunc next=self->fn_80176004(link->flags&0x800);
 StepFunc step=self->fn_80176028(link->flags&0x800);
 int lastWidth=0;
 int first=1;
 Node* node=next(arg2);
 float widthScale;
 float one;
 const float zero=lbl_805A301C;
 one=lbl_805A3020;
 while(node) {
 widthScale=lbl_805A3024;
 const float epsilon=lbl_805A3018;
 float product=node->a*node->c;
 float weight=product* *(float*)((char*)node->material+0x58);
 if(!(weight<epsilon)) {
 ShapeData* nodeData=*(ShapeData**)((char*)node->material+0x24);
 unsigned int mode=nodeData->link.flags&0x6000;
 float extent;
 switch(mode) {
 case 0x4000: extent=node->b*node->c; break;
 case 0x2000: extent=node->a*node->d; break;
 case 0x6000: extent=node->a*node->c; break;
 default: extent=node->b*node->d; break;
 }
 radius=extent* *(float*)((char*)node->material+0x5c);
 if(!(radius<epsilon)) {
 VEC3 position,delta,difference;
 VEC3Sub(&difference,&node->first,&node->second);
 delta=difference;
 *(VectorBits*)&position=*(VectorBits*)&node->first;
 if(normalizeVector(&delta,epsilon,zero,one)) {
 delta *= radius;
 VEC3Sub(&delta,&position,&delta);
 const float* selected=weight<lbl_8059E8C8?&weight:&lbl_8059E8C8;
 int width=(int)(widthScale* *selected);
 if((unsigned char)width) {
 if((unsigned char)lastWidth!=(unsigned char)width) {
 lastWidth=width;
 GXSetLineWidth(width,5);
 fn_801750E8(arg0,node,link,arg1,first,1);
 } else fn_801750E8(arg0,node,link,arg1,first,0);
 hasColor=*(unsigned char*)((char*)arg0+0xae)!=0;
 first=0;
 GXBegin((GXPrimitive)0xa8,(GXVtxFmt)0,2);
 WGPIPE.f=position.x; WGPIPE.f=position.y; WGPIPE.f=position.z;
 if(hasColor) { WGPIPE.f=lbl_805A301C; WGPIPE.f=lbl_805A301C; }
 WGPIPE.f=delta.x; WGPIPE.f=delta.y; WGPIPE.f=delta.z;
 if(hasColor) { WGPIPE.f=lbl_805A301C; WGPIPE.f=lbl_805A3020; }
 }
 }
 }
 }
 node=step(arg2,node);
 }
}
