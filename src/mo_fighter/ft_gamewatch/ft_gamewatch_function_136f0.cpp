#include <so/so_module_accesser.h>
#pragma force_active on
class WorkView {
public:
 virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
 virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
 virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
 virtual float getFloat(unsigned long);
 virtual void e0(); virtual void e1(); virtual void e2();
 virtual void setFloat(float, unsigned long);
 virtual int isFlag(unsigned long);
 virtual void onFlag(unsigned long);
 virtual void clearAll(unsigned long);
};
class ControllerView {
public:
 virtual void f00(); virtual void f01(); virtual void f02(); virtual void f03();
 virtual void f04(); virtual void f05(); virtual void f06(); virtual void f07();
 virtual void f08(); virtual void f09(); virtual void f10(); virtual void f11();
 virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
 virtual float getValue();
 virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
 virtual void f20(); virtual void f21();
 virtual unsigned char getByte();
};
extern "C" {
extern const float lbl_107_rodata_98;
extern const float lbl_107_rodata_9C;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);
void fn_107_14328(void*, soModuleAccesser*);
}
extern "C" void fn_107_136F0(void* self, soModuleAccesser* accesser) {
 reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule)->clearAll(0x22000011);
 if (reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule)->getFloat(0x21000005) > lbl_107_rodata_98) {
  reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule)->setFloat(lbl_107_rodata_9C, 0x21000005);
 } else if (!reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule)->isFlag(0x22000012)) {
  reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule)->onFlag(0x22000012);
  reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule)->onFlag(0x22000011);
 }
 float negativeSpeed;
 float threshold;
 float product;
 int limit;
 threshold = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xC32, 0);
 limit = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x59F7, 0);
 WorkView* work = reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule);
 ControllerView* controller = reinterpret_cast<ControllerView*>(accesser->m_enumerationStart->m_controllerModule);
 product = controller->getValue() * -work->getFloat(0x21000004);
 if (product >= threshold) {
  if (reinterpret_cast<ControllerView*>(accesser->m_enumerationStart->m_controllerModule)->getByte() < limit) {
   reinterpret_cast<WorkView*>(accesser->m_enumerationStart->m_workManageModule)->onFlag(0x22000010);
  }
 }
 fn_107_14328(self, accesser);
}