
#pragma force_active on
class soCollisionHitModuleImpl {
public:
 virtual void isNull();
 virtual ~soCollisionHitModuleImpl();
 virtual void fn_27_42F88();
 virtual void fn_27_43044();
 virtual void fn_27_430F8();
 virtual void fn_27_43184(int);
 virtual int fn_27_431DC();
 virtual void fn_27_43480();
 virtual void fn_27_43504();
 virtual void fn_27_43528();
 virtual void fn_27_435A4();
 virtual void fn_27_43620();
 virtual void fn_27_43664();
 virtual void fn_27_436CC();
 virtual void fn_27_43724(int);
 virtual void fn_27_4377C();
 virtual void fn_27_437E4();
 virtual void fn_27_4384C();
 virtual void fn_27_438B4();
};
class soPostureModuleImpl {
public:
 virtual void isNull();
 virtual ~soPostureModuleImpl();
 virtual void fn_27_2362C();
 virtual void fn_27_236B0();
 virtual void fn_27_25088();
 virtual void fn_27_23E84();
 virtual void fn_27_25184();
 virtual void fn_27_2370C();
 virtual void fn_27_23728();
 virtual void fn_27_23E28();
 virtual void fn_27_23CC0();
 virtual void fn_27_25068();
 virtual void fn_27_23A9C();
 virtual void fn_27_23B18();
 virtual void fn_27_250FC();
 virtual void fn_27_250A4();
 virtual void fn_27_23BF8();
 virtual void fn_27_251B8();
 virtual void fn_27_251B0();
};
class Class_1250 {
public:
 virtual void fn_27_13C90();
 virtual void fn_27_14068();
 virtual void fn_27_140C0();
 virtual void fn_27_1412C();
 virtual void fn_27_14134();
 virtual void fn_27_14370();
 virtual void fn_27_14A28();
 virtual void fn_27_14A30();
 virtual void fn_27_14A38();
 virtual void fn_27_14A48();
 virtual void fn_27_14A68();
 virtual void fn_27_14AD8();
 virtual void fn_27_14A60();
 virtual void fn_27_14D08();
 virtual void fn_27_14EDC();
 virtual void fn_27_14D00();
 virtual void fn_27_14B80();
 virtual void fn_27_14B88();
 virtual void fn_27_16A70(int);
};
class Class_20E8 {
public:
 virtual void fn_27_1F1B8();
 virtual void fn_27_14068();
 virtual void fn_27_140C0();
 virtual void fn_27_1412C(int, void*);
 virtual void fn_27_14134();
 virtual void fn_27_14370();
 virtual void fn_27_14A28();
 virtual void fn_27_14A30();
 virtual void fn_27_14A38();
 virtual void fn_27_14A48();
 virtual void fn_27_14A68();
 virtual void fn_27_14AD8();
 virtual void fn_27_14A60();
 virtual void fn_27_14D08();
 virtual void fn_27_14EDC();
 virtual void fn_27_14D00();
 virtual void fn_27_14B80();
 virtual void fn_27_14B88();
 virtual void fn_27_16A70();
};
struct gfTask_base { char pad[0x28]; void* value; char pad2[0x10]; };
class gfTask : public gfTask_base {
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
 virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual int fn_27_248088();
};
struct Modules {
 char pad[0x30];
 soPostureModuleImpl* posture;
 char pad34[8];
 soCollisionHitModuleImpl* hit;
 char pad40[0x24];
 Class_1250* other;
 char pad68[8];
 Class_20E8* work;
};
struct Object { char pad[0xd8]; Modules* modules; };
struct Context { char pad[0x60]; Object* object; };
struct Event { int kind; unsigned char flag; char pad5[3]; int value; char padc[0x10]; unsigned char flag2; };
extern "C" void fn_27_28FC34(void*, void*);
extern "C" void fn_27_29E760(void*, Context* context, Event* event, Object* object, gfTask* task, int arg) {
 if (arg == 0) {
  switch (event->kind) {
  case 8:
   if (object->modules->hit->fn_27_431DC() == 0 && task->fn_27_248088() == 0) {
    event->flag = 1;
    event->flag2 = 1;
    event->value = 12;
    object->modules->hit->fn_27_43184(-1);
    object->modules->hit->fn_27_43724(0);
    object->modules->posture->fn_27_25088();
    fn_27_28FC34(context, task->value);
   }
   break;
  case 9:
  case 0x3d:
   if (object->modules->hit->fn_27_431DC() != 0) {
    context->object->modules->other->fn_27_16A70(0x12000002);
    context->object->modules->work->fn_27_1412C(11, context->object);
   }
   break;
  }
 }
}
