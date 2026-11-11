#include <types.h>
#pragma force_active on

class Obj {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual int slot3();
 virtual int slot4(u32);
 virtual void slot5(int, u32);
 virtual Obj* slot6(int);
 virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(u32);
 virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
 virtual u32 slot17(u32);
 virtual void slot18();
 virtual void slot19(u32);
};

class Ret {
public:
 virtual void r0(); virtual void r1(); virtual void r2();
 virtual void r3(); virtual void r4(); virtual void r5();
 virtual void r6();
};

struct Modules {
 char p0[0x14]; Obj* o14;
 char p1[0x4c]; Obj* work;
 char p2[0x14]; Obj* o7c;
};
struct Fighter { char p[0xd8]; Modules* m; };

extern "C" void fn_27_16C2FC(void* unused, Fighter* self, s32 arg3) {
 self->m->work->slot19(0x12000037);
 if (self->m->o14->slot3() != 2) {
  self->m->work->slot19(0x12000011);
 }
 if (self->m->work->slot17(0x22000012) == 1) {
  if (self->m->work->slot4(0x10000039) > 0) {
   return;
  }
  if (arg3 != 0x114) {
   if (arg3 < 0x114) {
    if (arg3 < 0xe) {
     if (arg3 >= 0xc) goto do_block;
     goto done;
    }
    goto done;
   }
   goto done;
  } else {
   goto do_block;
  }
  done:
   return;
  do_block:
  {
   Ret* r = (Ret*)self->m->o7c->slot6(4);
   r->r6();
   self->m->work->slot5(0, 0x10000038);
  }
  return;
 }
}