#pragma force_active on
#define V(n) virtual void v##n();
#define V10(n) V(n##0) V(n##1) V(n##2) V(n##3) V(n##4) V(n##5) V(n##6) V(n##7) V(n##8) V(n##9)
struct Vec3 { float x,y,z; };
struct Pad8 { char pad[8]; };
struct Ctl {
 V(0) V(1) V(2) virtual int s5(); V(6) V(7) V(8) V(9) virtual void s10(int);
 V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
 V(81) V(82) V(83) V(84) V(85) V(86)
 virtual void s87(Vec3*, Vec3*); V(88) virtual void s89(int); virtual int s90();
};
struct Holder : Pad8 {
 V10(0) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18)
 virtual void s21(int,int); virtual unsigned char s22(int);
};
struct Obj2184 { char pad[0x34]; int i34; };
struct Mid2 { char pad0[0x10]; Holder* h10; Ctl* c14; char pad1[0x54-0x18]; Ctl* c54; };
struct Mid { char pad[0xd8]; Mid2* m2; };
struct Self : Pad8 {
 V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9)
 V10(10) V10(11) V10(12) V10(13) V10(14) V10(15) V10(16)
 V(170) V(171) V(172) V(173) V(174) V(175) V(176) V(177) V(178)
 virtual void v181();
 char pad1[0x6c-0x0c]; Mid* m6c; char pad2[0x2184-0x70]; Obj2184* p2184;
};
extern "C" void wnemReport__FPCce(const char*, ...);
extern "C" Vec3* fn_41_5AC4(Vec3*, float, float, float);
extern "C" const char lbl_41_data_4684[];
extern "C" const char lbl_41_data_46A3[];
extern "C" const float lbl_41_rodata_E28;
extern "C" void fn_41_31B34(Self* self) {
 wnemReport__FPCce(lbl_41_data_4684);
 if (self->m6c->m2->c54->s90() == 0) { wnemReport__FPCce(lbl_41_data_46A3); return; }
 Ctl* c = self->m6c->m2->c54;
 Vec3 a; Vec3 b;
 c->s87(fn_41_5AC4(&a, lbl_41_rodata_E28, lbl_41_rodata_E28, lbl_41_rodata_E28), fn_41_5AC4(&b, lbl_41_rodata_E28, lbl_41_rodata_E28, lbl_41_rodata_E28));
 self->m6c->m2->c54->s89(1);
 self->m6c->m2->c54->s10(3);
 self->v181();
 if (self->p2184->i34 != 0) {
  if (self->m6c->m2->c14->s5() == 2) {
   if (self->m6c->m2->h10->s22(0) != 6) self->m6c->m2->h10->s21(5,0);
  } else self->m6c->m2->h10->s21(1,0);
 }
}