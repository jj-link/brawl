#include <so/so_module_accesser.h>
#include <so/status/so_status_module_impl.h>
#include <so/link/so_link_module_impl.h>
#include <so/posture/so_posture_module_simple.h>
#pragma force_active on
extern "C" void fn_27_12DCA8(void*);
extern "C" void fn_123_8E3C(void* p) {
 fn_27_12DCA8(p);

 if ((*reinterpret_cast<soModuleAccesser**>((char*)p + 0x60))->getStatusModule().getStatusKind() == 0x116) {
  if ((*reinterpret_cast<soModuleAccesser**>((char*)p + 0x60))->getLinkModule().isModelConstraint() == 1) {
   (*reinterpret_cast<soModuleAccesser**>((char*)p + 0x60))->getPostureModule().setPos(&(*reinterpret_cast<soModuleAccesser**>((char*)p + 0x60))->getLinkModule().getModelConstraintTargetNodePosition());
  }
 }
}