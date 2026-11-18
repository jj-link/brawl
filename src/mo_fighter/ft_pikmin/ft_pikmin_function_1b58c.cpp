#pragma force_active on
struct Event { int kind; bool flag; };
struct CompA {
virtual void f0(); virtual void f1(); virtual void f2();
virtual void f3(int,int,bool); virtual void f4();
};
struct CompB {
virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(int,Event*);
};
class Object_vptr_0 { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual int slot4(int); virtual void slot5(int,int); virtual void slot6();
virtual void slot7(int); virtual void slot8(); virtual void slot9(); virtual void slot10();
virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
};
struct Thr { char pad[0x20]; float f20,f24; };
struct Inner { char pad0[0x54]; CompB* c54; CompA* c58; char pad1[8]; Object_vptr_0* c64; };
struct Mid { char pad[0xd8]; Inner* inner; };
struct Outer { char pad0[0x60]; Mid* mid; char pad1[0x3144-0x64]; Thr* thr; };
extern "C" void fn_113_1B58C(Outer* self) {
int r=self->mid->inner->c64->slot4(0x10000008);
if(r<2) {
self->mid->inner->c64->slot7(0x10000009);
int v=self->mid->inner->c64->slot4(0x10000009);
if(r==0 && (float)v>=self->thr->f20) {
 self->mid->inner->c58->f3(0,1,1);
 self->mid->inner->c64->slot5(1,0x10000008);
} else if(r==1 && (float)v>=self->thr->f24) {
 self->mid->inner->c58->f3(0,2,1);
 self->mid->inner->c64->slot5(2,0x10000008);
 Event e; e.kind=0x45b; e.flag=false;
 self->mid->inner->c54->f15(1,&e);
} else {
 return;
}
 self->mid->inner->c58->f4();
}
}
