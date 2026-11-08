#pragma force_active on
extern "C" void* fn_27_1D53E4(void*, unsigned int, unsigned int);
extern "C" float fn_27_1D5658(void*, void*);
extern float lbl_27_rodata_2720;
struct State { char pad[0xc3c]; int a, b; };
struct Pair { int a,b; };
struct Entry { void* p; int a,b; };
struct Class_270C0_base { State* state; char pad[8]; };
class Class_270C0 : public Class_270C0_base {
public:
 virtual void fn_27_11110C(); virtual void fn_27_112FEC(); virtual void fn_27_1113B8();
 virtual void fn_27_111850(); virtual void fn_27_111894(); virtual void fn_27_1118A0();
 virtual void fn_27_1118E4(); virtual void fn_27_111A14(); virtual void fn_27_110FC8();
 virtual void fn_27_111AB8(); virtual void fn_27_112E78(); virtual void fn_27_112E94();
 virtual void fn_27_112EB0(int,int,int); virtual void fn_27_112ECC(int,int,int);
 virtual void fn_27_112EE8(); virtual void fn_27_112F04(); virtual void fn_27_112F20();
 virtual void fn_27_112F3C(Pair*); virtual void fn_27_112F98(Entry*);
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual int slot3();
 virtual void slot4(); virtual void slot5(void*,unsigned int); virtual void slot6();
 virtual void slot7(); virtual void slot8(float);
};
struct Accesser {
 char pad0[0x14]; Object_vptr_0* a;
 char pad1[0x4c]; Object_vptr_0* b;
 char pad2[0x5c]; Object_vptr_0* c;
};
struct Fighter { char pad[0xd8]; Accesser* accesser; };
extern "C" void fn_27_1D6434(int arg0, int arg1, int arg2, Class_270C0* arg3, Fighter* arg4) {
 if (arg0 != 1) {
  int old0 = arg3->state->a;
  int old1 = arg3->state->b;
  if (old0 != arg0 || old1 != arg1) {
   Pair p; p.a=arg0; p.b=arg1;
   arg3->fn_27_112F3C(&p);
   arg4->accesser->c->slot8(lbl_27_rodata_2720);
  }
  if (arg0 == 2 && (old0 != arg0 || old1 != arg1 || arg2 != 0)) {
   arg3->fn_27_112ECC(1,12,0);
   void* value = fn_27_1D53E4((char*)arg3->state+0x9e8,12,0);
   arg4->accesser->b->slot5(value,0x10000035);
   if (arg4->accesser->a->slot3()==2) arg3->fn_27_112ECC(1,14,0);
   arg3->fn_27_112EB0(0,0x21,0);
   Entry e; e.p=fn_27_1D53E4((char*)arg3->state+0x9e8,12,0); e.a=arg1; e.b=0;
   arg3->fn_27_112F98(&e);
   float f=fn_27_1D5658((char*)arg3->state+0xcc8,&e);
   arg4->accesser->c->slot8(f);
  }
 }
}