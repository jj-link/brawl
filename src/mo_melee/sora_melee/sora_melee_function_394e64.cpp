#include <so/model/so_model_module_simple.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual int slot4(int);
};
extern float lbl_27_rodata_7D70;
extern "C" Vec3f fn_27_394E64(void* arg, int flag) {
 char* ctx = *(char**)(*(char**)((char*)arg + 0x60) + 0xd8);
 Object_vptr_0* obj = *(Object_vptr_0**)(ctx + 0x64);
 switch (obj->slot4(0x1000000c)) {
 case 0:
  if (flag == 0) {
   return (*(soModelModule**)(*(char**)(*(char**)((char*)arg + 0x60) + 0xd8) + 4))->getNodeGlobalPosition(6, false);
  } else {
   return (*(soModelModule**)(*(char**)(*(char**)((char*)arg + 0x60) + 0xd8) + 4))->getNodeGlobalPosition(0x2d, false);
  }
 case 1:
  if (flag == 0) {
   return (*(soModelModule**)(*(char**)(*(char**)((char*)arg + 0x60) + 0xd8) + 4))->getNodeGlobalPosition(0x18, false);
  } else {
   return (*(soModelModule**)(*(char**)(*(char**)((char*)arg + 0x60) + 0xd8) + 4))->getNodeGlobalPosition(6, false);
  }
 case 2:
  if (flag == 0) {
   return (*(soModelModule**)(*(char**)(*(char**)((char*)arg + 0x60) + 0xd8) + 4))->getNodeGlobalPosition(0x18, false);
  } else {
   return (*(soModelModule**)(*(char**)(*(char**)((char*)arg + 0x60) + 0xd8) + 4))->getNodeGlobalPosition(0x2d, false);
  }
 default:
  return Vec3f(lbl_27_rodata_7D70, lbl_27_rodata_7D70, lbl_27_rodata_7D70);
 }
}