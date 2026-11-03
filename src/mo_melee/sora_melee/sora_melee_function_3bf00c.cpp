#include <so/so_value_accesser.h>
#pragma force_active on
class WorkModule {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual int getInt(unsigned int);
 virtual void setInt(int, unsigned int);
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual float getFloat(unsigned int);
 virtual void setFloat(unsigned int, float);
 virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual void onFlag(unsigned int);
};
class Controller {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual float stick();
};
class Posture {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
 virtual float lr();
};
struct Modules { char pad[0xc]; Posture* posture; char pad1[0x4c]; Controller* controller; char pad2[4]; WorkModule* work; };
struct Owner { char pad[0xd8]; Modules* modules; };
extern float lbl_27_rodata_8088;
extern float lbl_27_rodata_808C;
extern "C" void fn_27_3BF00C(void*, Owner* owner) {
 int count = owner->modules->work->getInt(0x2000000d);
 if (count > 0) {
  if (count - 1 <= 0) {
   float direction = owner->modules->work->getFloat(0x21000011);
   float stick = owner->modules->controller->stick();
   if (stick > soValueAccesser::getConstantFloat((soModuleAccesser*)owner, 0xc70, 0)) direction = lbl_27_rodata_8088;
   else if (stick < -soValueAccesser::getConstantFloat((soModuleAccesser*)owner, 0xc70, 0)) direction = lbl_27_rodata_808C;
   if (direction != owner->modules->posture->lr()) {
    owner->modules->work->onFlag(0x22000014);
    owner->modules->work->setFloat(0x21000011, direction);
   }
  }
  owner->modules->work->setInt(count - 1, 0x2000000d);
 }
}