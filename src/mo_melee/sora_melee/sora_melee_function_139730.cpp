#include <ft/ft_manager.h>
#include <it/it_manager.h>
#pragma force_active on
class Obj;
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual int slot3();
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
 virtual void slot16();
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
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34(int, Obj*);
};
struct Modules {
 char pad[0x14];
 Object_vptr_0* status;
 char pad18[0x4c];
 Object_vptr_0* work;
 char pad68[8];
 Object_vptr_0* action;
};
class Obj { public: char pad[0xd8]; Modules* modules; };
struct Self { char pad[0x28]; int value; char pad2[0x34]; Obj* obj; };
extern "C" int fn_27_2A9DB8(itManager*, Vec3f*, int, int);
extern "C" void fn_27_139730(Self* self, int a, int b, unsigned int c) {
 Obj* obj = self->obj;
 if (a != -1) {
  int v = self->value;
  Vec3f pos = g_ftManager->getFighterCenterPos(a, -1);
  int result = fn_27_2A9DB8(itManager::getInstance(), &pos, v, v);
  obj->modules->work->slot5(result, 0x10000030);
  obj->modules->work->slot5(a, 0x1000002f);
  obj->modules->action->slot34(0xf4, obj);
 } else if (obj->modules->work->slot4(0x1000002f) != -1) {
  obj->modules->work->slot5(-1, 0x1000002f);
  if (c == 1) {
   int v = self->value;
   Vec3f pos = g_ftManager->getFighterCenterPos(b, -1);
   int result = fn_27_2A9DB8(itManager::getInstance(), &pos, v, v);
   obj->modules->work->slot5(result, 0x10000030);
   if (obj->modules->status->slot3() != 5)
    obj->modules->action->slot34(0xf5, obj);
  }
 }
}