#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual int slot3();
 virtual int slot4(unsigned int);
 virtual void slot5(int, unsigned int);
 virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(unsigned int); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual unsigned int slot17(unsigned int); virtual void slot18(); virtual void slot19(unsigned int);
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
};
class Event {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(int, void*);
};
class Toggle {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(int);
};
struct Modules {
 char p0[0xc]; Object_vptr_0* oC;
 char p1[4]; Object_vptr_0* o14;
 char p2[0x38]; Object_vptr_0* o50;
 char p3[0x10]; Object_vptr_0* work;
 char p4[8]; Event* event;
 char p5[0x50]; Toggle* toggle;
};
struct Fighter { char p[0xd8]; Modules* m; };
struct Arg { char p[0x60]; Fighter* fighter; };
extern "C" void fn_27_137B94(Arg* arg) {
 Fighter* f = arg->fighter;
 if (f->m->o14->slot3() != 5 &&
     f->m->work->slot4(0x10000023) >= 2 &&
     !f->m->work->slot17(0x12000032) &&
     !f->m->work->slot17(0x12000018)) {
   if (f->m->work->slot4(0x10000023) == 3) {
     f->m->work->slot5(2, 0x10000023);
     f->m->event->slot3(0xf2, f);
   } else {
     f->m->work->slot5(1, 0x10000023);
     f->m->event->slot3(0xf3, f);
   }
   return;
 }
 f = arg->fighter;
 f->m->work->slot12(0x1100000b);
 f->m->oC->slot23();
 if (f->m->work->slot17(0x12000014) == 1) {
   f->m->work->slot19(0x12000014);
   f->m->toggle->slot5(0);
   Object_vptr_0* o = f->m->o50;
   f->m->work->slot12(0x11000011);
   o->slot16();
 }
 if (f->m->work->slot17(0x12000015) == 1) {
   f->m->work->slot19(0x12000015);
   f->m->toggle->slot5(1);
   Object_vptr_0* o = f->m->o50;
   f->m->work->slot12(0x11000011);
   o->slot16();
 }
 f->m->work->slot5(0, 0x10000023);
}