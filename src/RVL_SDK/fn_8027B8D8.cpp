#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
class Object_vptr_0 {
public:
 virtual void slot0(int);
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void* slot4(u32, int);
 u16 size;
 s16 refs;
};
extern Object_vptr_0* lbl_805A0EB8;
extern Object_vptr_0* lbl_805A0EA8;
extern Object_vptr_0* lbl_805A0EE8;
extern Object_vptr_0* lbl_805A0EB0;
extern s8 lbl_805A0EA0;
extern void* (*lbl_8059EF40)(int,int);
extern "C" {
void fn_8027FF58();
void fn_8027E27C(void*);
void* fn_8027E5A8(void*,void*,int);
void fn_8027B89C(void*);
void fn_8027E9E0(void*);
void fn_8027B5D4();
void fn_8027B5D0();
void fn_80281E48();
extern char lbl_80486080[];
extern char lbl_80486120[];
}
class Class_8027D01C {
public:
 Class_8027D01C();
 char data[12];
};
struct Header {
 void* vtable;
 u16 size;
 s16 refs;
 Header(void* v) { refs=1; vtable=v; }
 static void* operator new(size_t n) {
 void* p=lbl_805A0EB8->slot4(n,0x16);
 ((Header*)p)->size=n;
 return p;
 }
};
struct First : Header {
 First() : Header(lbl_80486080) {}
};
struct Second : Header {
 Class_8027D01C sub;
 int a,b,c,d,e;
 Second(int x,int y) : Header(lbl_80486120), sub() {
 a=0;b=0;c=0x80000000;d=x;e=y;
 }
};
inline void release(Object_vptr_0* p) {
 if(p && p->size) {
 if(--p->refs==0) { if(p) p->slot0(1); }
 }
}
extern "C" int fn_8027B8D8(void* a,void* b,int c,int d) {
 if ((s8)((unsigned int)__cntlzw(lbl_805A0EA0) >> 5) != 0) {
 fn_8027FF58();
 if(a) {
 fn_8027E27C(a);
 if(!b) {
 b=lbl_8059EF40(0x320,0x10);
 if(b) b=fn_8027E5A8(b,a,0x10);
 fn_8027B89C(b);
 fn_8027E9E0(b);
 } else fn_8027B89C(b);
 } else { *(int*)0=0; return 1; }
 Object_vptr_0* p=(Object_vptr_0*)new First;
 release(lbl_805A0EE8);
 lbl_805A0EE8=p;
 p=(Object_vptr_0*)new Second(c,d);
 release(lbl_805A0EB0);
 lbl_805A0EB0=p;
 fn_8027B5D4();
 lbl_805A0EA8->slot2();
 lbl_805A0EA0=1;
 fn_8027B5D0();
 fn_80281E48();
 }
 return 0;
}
