#include <types.h>
#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*,u32,u32);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*,u32,u32);
extern "C" void fn_27_3BCFEC(void* owner,float* value,soModuleAccesser* self) {
 if(self->m_enumerationStart->m_kineticModule->getKineticType()==0x6B)return;
 if(self->m_enumerationStart->m_kineticModule->getKineticType()==0x6C)return;
 s32 r29; float f31; float f30;
 if(self->m_enumerationStart->m_statusModule->getPrevStatusKind(0)==0x120)
  f30=(float)(double)nw4r::math::FAbs(*value);
 else {
  r29=self->m_enumerationStart->m_workManageModule->getInt(0x20000002);
  if(r29<0)r29=0;
  else if(self->m_enumerationStart->m_statusModule->getPrevStatusKind(0)!=0x124 &&
   r29>getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self,0x5DC7,0))
   r29=getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(self,0x5DC7,0);
  float c4=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self,0xFB4,0);
  f31=(float)r29*c4;
  float base=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self,0xFB3,0);
  f30=base+f31;
 }
 self->m_enumerationStart->m_workManageModule->setFloat(f30,0x21000004);
 soWorkManageModule* work=self->m_enumerationStart->m_workManageModule;
 float lim=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self,0xFBA,0);
 if(work->getFloat(0x21000004)>lim) {
  work=self->m_enumerationStart->m_workManageModule;
  work->setFloat(getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self,0xFBA,0),0x21000004);
 }
 work=self->m_enumerationStart->m_workManageModule;
 float c5=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self,0xFB5,0);
 work->setFloat(f30*c5,0x21000005);
 work=self->m_enumerationStart->m_workManageModule;
 float lim2=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self,0xFBB,0);
 if(work->getFloat(0x21000005)>lim2) {
  soWorkManageModule* lastWork=self->m_enumerationStart->m_workManageModule;
  lastWork->setFloat(getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self,0xFBA,0),0x21000005);
 }
}