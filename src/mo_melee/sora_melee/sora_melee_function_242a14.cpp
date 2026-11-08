#pragma force_active on
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual unsigned int slot36();
};
struct Self {
 char pad0[0x40]; unsigned char state; char pad1[0x33];
 Object_vptr_3c* a; Object_vptr_3c* b; Object_vptr_3c* c; Object_vptr_3c* d;
};
extern "C" void fn_27_242A14(Self* self) {
 unsigned int done = 0;
 unsigned char state = self->state;
 do {
  switch (state) {
  case 1:
   if ((self->a == 0 ? 0 : self->a->slot36()) == 1U) done = 1;
   state = 2; break;
  case 2:
   if ((self->b == 0 ? 0 : self->b->slot36()) == 1U) done = 1;
   state = 3; break;
  case 3:
   if ((self->c == 0 ? 0 : self->c->slot36()) == 1U) done = 1;
   state = 4; break;
  case 4:
   if ((self->d == 0 ? 0 : self->d->slot36()) == 1U) done = 1;
   state = 5; break;
  case 5: state = 6; done = 1; break;
  case 6: state = 7; done = 1; break;
  case 7: done = 1; break;
  }
 } while (done != 1U);
 self->state = state;
}