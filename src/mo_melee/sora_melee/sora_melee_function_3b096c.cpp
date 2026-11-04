#pragma force_active on
class soNullable {
public:
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual int slot16(); virtual void slot17(); virtual void slot18();
};
class Identity {
public:
 virtual void isNull(); virtual void slot1(); virtual int slot2();
};
class IdentityModule {
public:
 virtual void isNull(); virtual void slot1(); virtual Identity* slot2();
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
 virtual void fn_27_7B274(); virtual void fn_27_7AC18(); virtual void fn_27_7AC28();
 virtual void fn_27_7AB50(); virtual void fn_27_7B2EC(); virtual void fn_27_7AB10();
 virtual void fn_27_7AD2C(); virtual void fn_27_7AEDC(); virtual void fn_27_7B22C();
 virtual void fn_27_7AC38(); virtual void fn_27_7ADE8(); virtual void fn_27_7AF98();
 virtual void fn_27_7B0B0(); virtual unsigned int fn_27_7ABD8();
};
struct Accesser;
class Work {
public:
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(unsigned int, Accesser*);
};
struct Modules {
 char pad0[0x18]; IdentityModule* identity;
 char pad1[0x64-0x1c]; Work* work;
 char pad2[0x70-0x68]; soNullable* query;
 char pad3[0xbc-0x74]; Class_90D8* action;
};
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Accesser* accesser; };
struct Event { char pad[0x20]; signed char id; unsigned char kind; };
extern "C" void fn_27_3B096C(Object* self, Event* event) {
 if (event && self->accesser->modules->query->slot16() == 0) {
  if (event->kind == 3) {
   if (event->id != self->accesser->modules->identity->slot2()->slot2()) {
    if (self->accesser->modules->action->fn_27_7ABD8() == 1U) {
     Accesser* accesser = self->accesser;
     accesser->modules->work->slot18(0x22000005, accesser);
    }
   }
  } else {
   Accesser* accesser = self->accesser;
   accesser->modules->work->slot18(0x22000004, accesser);
  }
 }
}