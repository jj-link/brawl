#include <so/so_value_accesser.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual int slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13(float, unsigned long);
 virtual void slot14();
 virtual void slot15();
 virtual int slot16();
 virtual void slot17();
 virtual void slot18(unsigned long);
};
extern "C" void fn_27_31121C(void*, soModuleAccesser* obj) {
 switch (reinterpret_cast<Object_vptr_0*>(obj->m_enumerationStart->m_statusModule)->slot16()) {
 case 0x117:
 case 0x119:
  if (reinterpret_cast<Object_vptr_0*>(obj->m_enumerationStart->m_situationModule)->slot3() == 2) {
   int value = soValueAccesser::getConstantInt(obj, 0x5dc8, 0);
   reinterpret_cast<Object_vptr_0*>(obj->m_enumerationStart->m_workManageModule)->slot13(value, 0x11000000);
   float value2 = soValueAccesser::getConstantFloat(obj, 0xfb9, 0);
   reinterpret_cast<Object_vptr_0*>(obj->m_enumerationStart->m_workManageModule)->slot13(value2, 0x11000001);
   reinterpret_cast<Object_vptr_0*>(obj->m_enumerationStart->m_workManageModule)->slot18(0x12000003);
  }
 case 0x118:
 default:
  break;
 }
}