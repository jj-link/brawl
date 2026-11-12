#pragma force_active on
struct Arg { int f0; int f4,f8,fC,f10; };
struct Obj { char pad[0x40]; int f40; char pad2[0x264-0x44]; int f264,f268,f26c,f270; char pad3[0x6160-0x274]; int f6160; };
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long,int);
extern "C" Obj* fn_11_BC(Obj*);
extern "C" void fn_11_52C(Obj*,const Arg&);
extern "C" void fn_11_1468(Obj*);
extern "C" void* fn_11_7590(int);
extern void* lbl_11_bss_8;
extern "C" Obj* fn_11_0(const Arg& p) {
 Obj* obj=(Obj*)__nw__FUlQ25Heaps8HeapType(0x616c,0x2a);
 if(obj) obj=fn_11_BC(obj);
 int b,a,t,c,d;
 t=p.f0;
 a=p.f4;
 obj->f40=t;
 b=p.f8;
 obj->f264=a;
 c=p.f10;
 obj->f268=b;
 d=p.fC;
 obj->f26c=c;
 obj->f270=d;
 if((unsigned int)t<=2) fn_11_52C(obj,p);
 else { if(t==3) lbl_11_bss_8=fn_11_7590(1); fn_11_1468(obj); obj->f6160=0; }
 return obj;
}
