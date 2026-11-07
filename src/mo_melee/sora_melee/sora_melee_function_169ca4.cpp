#include <so/so_value_accesser.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(int); virtual void slot5(int,int); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual float slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual int slot16(); virtual bool slot17(int); virtual void slot18(int); virtual void slot19();
 virtual void slot20(); virtual int slot21();
};
struct Modules { char pad[8]; Object_vptr_0* motion; char padc[0x58]; Object_vptr_0* work; char pad68[8]; Object_vptr_0* status; };
struct Accesser { char pad[0xd8]; Modules* modules; };
extern "C" float lbl_27_rodata_20E8;
extern "C" void fn_27_169CA4(void*, Accesser* a) {
 if (!a->modules->work->slot17(0x12000003)) {
  int status = a->modules->status->slot16();
  if (status == 22) {
   float f = soValueAccesser::getConstantFloat((soModuleAccesser*)a,0xc02,0);
   if (lbl_27_rodata_20E8 != f && f <= a->modules->motion->slot12())
    a->modules->work->slot18(0x22000010);
  } else if (status == 23) {
   float f = soValueAccesser::getConstantFloat((soModuleAccesser*)a,0xc01,0);
   if (lbl_27_rodata_20E8 != f && f <= a->modules->motion->slot12())
    a->modules->work->slot18(0x22000010);
  } else if (status == 24) {
   int kind = a->modules->motion->slot21();
   int count = a->modules->work->slot4(0x20000002);
   a->modules->work->slot5(count+1,0x20000002);
   float limit = soValueAccesser::getConstantFloat((soModuleAccesser*)a,kind+0xb9c,0);
   if (count+1 >= (int)limit)
    a->modules->work->slot18(0x22000010);
  }
 }
}