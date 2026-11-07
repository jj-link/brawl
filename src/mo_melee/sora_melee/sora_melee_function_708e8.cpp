#include <ac/ac_cmd_interpreter.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual int slot17();
};
extern "C" int fn_27_708E8(acCmdInterpreter* self) {
 if (self->acCmdInterpreter::isBreakInterpret() == true) return 1;
 acCmdInterpreterStackData* data = self->getLastSystemStackData();
 if (!data) return 0;
 switch (data->kind) {
 case 8:
  if (*(void**)((char*)self + 0x44)) {
   Object_vptr_0* obj = *(Object_vptr_0**)(*(char**)(*(char**)((char*)self + 0x44) + 0xd8) + 8);
   if (obj->slot17() == 0) return 1;
   if (*(int*)((char*)self + 0x4c) != 0) return 1;
  }
  *(const acAnimCmdConv**)((char*)self + 0x4c) = data->addressData;
  self->popSystemStack();
  break;
 case 9: return 1;
 }
 return 0;
}