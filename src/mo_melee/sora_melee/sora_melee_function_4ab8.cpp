#pragma force_active on
typedef unsigned char u8;
struct Accesser;
struct Index { short value; short pad; Index(short v) : value(v) {} };
#define S(n) virtual void slot##n()
class Normal {
public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C);
S(30); S(34); S(38); S(3C); S(40); S(44); S(48); S(4C); S(50); S(54);
S(58); S(5C); S(60); S(64); S(68); S(6C); S(70); S(74); S(78); S(7C);
S(80); S(84); S(88); S(8C); S(90); S(94); S(98); S(9C); S(A0); S(A4);
S(A8); S(AC); S(B0); S(B4); S(B8); S(BC); S(C0); S(C4); S(C8); S(CC);
S(D0); S(D4); S(D8); S(DC); S(E0); S(E4); S(E8); S(EC); S(F0); S(F4);
S(F8); S(FC); S(100); S(104); S(108); S(10C); S(110); S(114); S(118); S(11C);
S(120); S(124); S(128); S(12C); S(130); S(134); S(138); S(13C); S(140); S(144);
S(148); S(14C); S(150); S(154); S(158); S(15C);
};
struct Prefix { int pad[2]; };
class NormalP : public Prefix {
public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C);
S(30); S(34); S(38); S(3C); S(40); S(44); S(48); S(4C); S(50); S(54);
S(58); S(5C); S(60); S(64); S(68); S(6C); S(70); S(74); S(78); S(7C);
S(80); S(84); S(88); S(8C); S(90); S(94); S(98); S(9C); S(A0); S(A4);
S(A8); S(AC); S(B0); S(B4); S(B8); S(BC); S(C0); S(C4); S(C8); S(CC);
S(D0); S(D4); S(D8); S(DC); S(E0); S(E4); S(E8); S(EC); S(F0); S(F4);
S(F8); S(FC); S(100); S(104); S(108); S(10C); S(110); S(114); S(118); S(11C);
S(120); S(124); S(128); S(12C); S(130); S(134); S(138); S(13C); S(140); S(144);
S(148); S(14C); S(150); S(154); S(158); S(15C);
};
struct TaskPrefix { char pad[0x3c]; };
class NormalTask : public TaskPrefix {
public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C);
S(30); S(34); S(38); S(3C); S(40); S(44); S(48); S(4C); S(50); S(54);
S(58); S(5C); S(60); S(64); S(68); S(6C); S(70); S(74); S(78); S(7C);
S(80); S(84); S(88); S(8C); S(90); S(94); S(98); S(9C); S(A0); S(A4);
S(A8); S(AC); S(B0); S(B4); S(B8); S(BC); S(C0); S(C4); S(C8); S(CC);
S(D0); S(D4); S(D8); S(DC); S(E0); S(E4); S(E8); S(EC); S(F0); S(F4);
S(F8); S(FC); S(100); S(104); S(108); S(10C); S(110); S(114); S(118); S(11C);
S(120); S(124); S(128); S(12C); S(130); S(134); S(138); S(13C); S(140); S(144);
S(148); S(14C); S(150); S(154); S(158); S(15C);
};
class Get2C { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); virtual int slot2C();
};
class Set18 { public:
S(08); S(0C); S(10); S(14); virtual void slot18(int);
};
class Float18 { public:
S(08); S(0C); S(10); S(14); virtual void slot18(float);
};
class Call20 { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); virtual void slot20(Accesser*);
};
class Call24 { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); virtual void slot24(Accesser*);
};
class Call28 { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); virtual void slot28(Accesser*, short*);
};
class Call3C { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C); S(30); S(34); S(38); virtual void slot3C(int, int);
};
class Float80 { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C); S(30); S(34); S(38); S(3C); S(40); S(44); S(48); S(4C); S(50); S(54); S(58); S(5C); S(60); S(64); S(68); S(6C); S(70); S(74); S(78); S(7C); virtual void slot80(float);
};
class P20 : public Prefix { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); virtual void slot20(int);
};
class P38 : public Prefix { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C); S(30); S(34); virtual void slot38(int);
};
class P40 : public Prefix { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C); S(30); S(34); S(38); S(3C); virtual int slot40();
};
class P50 : public Prefix { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C); S(30); S(34); S(38); S(3C); S(40); S(44); S(48); S(4C); virtual int slot50();
};
class P34 : public Prefix { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C); S(30); virtual int slot34(int);
};
class P30 : public Prefix { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C); virtual void slot30(int);
};
class Task94 : public TaskPrefix { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C); S(30); S(34); S(38); S(3C); S(40); S(44); S(48); S(4C); S(50); S(54); S(58); S(5C); S(60); S(64); S(68); S(6C); S(70); S(74); S(78); S(7C); S(80); S(84); S(88); S(8C); S(90); virtual void slot94(int);
};
class Task9C : public TaskPrefix { public:
S(08); S(0C); S(10); S(14); S(18); S(1C); S(20); S(24); S(28); S(2C); S(30); S(34); S(38); S(3C); S(40); S(44); S(48); S(4C); S(50); S(54); S(58); S(5C); S(60); S(64); S(68); S(6C); S(70); S(74); S(78); S(7C); S(80); S(84); S(88); S(8C); S(90); S(94); S(98); virtual int slot9C();
};
#undef S
struct Modules {
 char pad0[4]; void* m04; void* m08; void* m0c; void* m10;
 char pad14[8]; void* m1c; void* m20; void* m24; void* m28; void* m2c; void* m30; void* m34; void* m38;
 char pad3c[8]; void* m44; void* m48; void* m4c;
 char pad50[12]; void* m5c; char pad60[8]; void* m68; char pad6c[4]; void* m70; char pad74[8]; void* m7c;
 char pad80[8]; void* m88; void* m8c; char pad90[12]; void* m9c; char pada0[8]; void* ma8; void* mac; char padb0[8]; void* mb8;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Singleton { char pad[0x40]; int mode; float rate; u8 enabled; };
extern "C" {
extern Singleton* lbl_27_bss_F0;
extern float lbl_27_rodata_78;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
unsigned int fn_27_5BEA8(void*);
}
inline Singleton* instance() {
 if (!lbl_27_bss_F0) {
  void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
  if (p) p = fn_27_5BCD0(p);
  lbl_27_bss_F0 = (Singleton*)p;
 }
 return lbl_27_bss_F0;
}
#define N(x) ((Normal*)(a->modules->x))
#define P(x,t) ((t*)(a->modules->x))
extern "C" void fn_27_4AB8(void* self) {
 Accesser* a = *(Accesser**)((char*)self+0x60);
 int stop = P(m44,Get2C)->slot2C();
 P(m04,P38)->slot38(1);
 if (fn_27_5BE80(instance()) == 1) {
  int status = P(mb8,P40)->slot40();
  N(m68)->slot10();
  P(mb8,P20)->slot20(1);
  Call3C* p = P(m5c,Call3C);
  p->slot3C(((Task9C*)self)->slot9C(),0);
  if (!status) P(m04,P38)->slot38(0);
  N(m0c)->slot74();
  N(m08)->slot154();
  P(m9c,NormalP)->slot28();
  N(m4c)->slot20();
  P(m48,Set18)->slot18(1);
  N(m88)->slot18();
  N(m70)->slot1C();
  N(m1c)->slot14();
  N(m20)->slot20();
  N(m24)->slot18();
  N(m28)->slot18();
  N(m2c)->slot18();
  N(m30)->slot14();
  N(m34)->slot14();
  N(ma8)->slot18();
  if (!status) N(mac)->slot18();
  P(m10,NormalP)->slot30();
  if (!stop) {
   N(m8c)->slot14();
   if (!status) P(m70,Call20)->slot20(a);
   P(m08,Float18)->slot18(lbl_27_rodata_78);
   if (!status) { Index v(-1); P(m7c,Call28)->slot28(a,&v.value); }
   else { Index v(-2); P(m7c,Call28)->slot28(a,&v.value); }
   ((Task94*)self)->slot94(1);
   P(m38,NormalP)->slot24();
  } else {
   if (!P(mb8,P40)->slot40()) P(m70,Call24)->slot24(a);
   Index v(8); P(m7c,Call28)->slot28(a,&v.value);
   ((Task94*)self)->slot94(0);
  }
 } else {
  P(mb8,P20)->slot20(0);
  P(m48,Set18)->slot18(0);
  P(m9c,NormalP)->slot28();
  Index v(8); P(m7c,Call28)->slot28(a,&v.value);
  ((Task94*)self)->slot94(0);
 }
 N(m08)->slot1C();
 if (instance()->enabled == 1) {
  switch (instance()->mode) {
  case 0:
   if (!stop) {
    N(m08)->slot158();
    P(m08,Float18)->slot18((instance(), lbl_27_bss_F0->rate));
   }
   N(m0c)->slot78(); break;
  case 1:
   if (!stop) P(m08,Float18)->slot18((instance(), lbl_27_bss_F0->rate));
   break;
  case 2:
   if (!stop) N(m08)->slot15C();
   break;
  }
  P(m0c,Float80)->slot80((instance(), lbl_27_bss_F0->rate));
 }
 if (P(m10,P50)->slot50() || P(m9c,P34)->slot34(1))
  ((NormalTask*)self)->slotB4();
 P(m9c,P30)->slot30(1);
 P(m10,P34)->slot34(fn_27_5BEA8(instance())==1);
 P(m10,NormalP)->slot44();
}