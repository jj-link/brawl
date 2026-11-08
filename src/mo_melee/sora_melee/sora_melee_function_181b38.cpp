#pragma force_active on
class Owner;
class Secondary;
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3(int, Owner*);
 virtual int slot4(unsigned int);
 virtual void slot5(int, unsigned int);
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual int slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual Secondary* slot28();
};
struct Base { char pad[8]; };
class Secondary : public Base {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual int slot10();
};
class Query : public Base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
 virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
 virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
 virtual void slot52(); virtual void slot53(); virtual void slot54();
 virtual unsigned int slot55(int, int);
};
struct Modules {
 char pad0[0x10]; Query* query;
 char pad14[0x50]; Object_vptr_0* work;
 char pad68[8]; Object_vptr_0* status;
 char pad74[0x1c]; Object_vptr_0* other;
};
class Owner { public: char pad[0xd8]; Modules* modules; };
extern "C" void fn_27_181B38(void*, Owner* owner) {
 switch (owner->modules->status->slot16()) {
 case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xbb: {
  int state = owner->modules->other->slot28()->slot10();
  int count = owner->modules->work->slot4(0x20000004);
  if (state == 0) {
   count++;
   if (count >= 3) {
    if (owner->modules->query->slot55(8, 0) == 1U)
     owner->modules->status->slot3(0, owner);
    else
     owner->modules->status->slot3(14, owner);
   }
  } else {
   count = 0;
  }
  owner->modules->work->slot5(count, 0x20000004);
  break;
 }
 }
}