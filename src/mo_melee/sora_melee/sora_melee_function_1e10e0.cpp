#include <so/model/so_model_module_impl.h>
#pragma force_active on
struct GlobalObject { void* vtable; };
extern "C" {
extern char lbl_27_data_1EA88[];
extern int lbl_27_data_12498;
extern signed char lbl_27_bss_51F8;
extern char lbl_27_bss_5194[];
extern GlobalObject lbl_27_bss_51FC;
void fn_27_82A94(void*, short);
void* __register_global_object(void*, void*, void*);
}
union Flags {
 unsigned int raw;
 struct { unsigned int pad : 8; unsigned int value : 4; unsigned int flag : 1; unsigned int rest : 19; } bits;
};
struct Obj { void* vtable; void* calc; Flags flags; };
static inline GlobalObject* getGlobal() {
 if (lbl_27_bss_51F8 == 0) {
  lbl_27_bss_51FC.vtable = 0;
  lbl_27_bss_51FC.vtable = &lbl_27_data_12498;
  __register_global_object(&lbl_27_bss_51FC, (void*)fn_27_82A94, lbl_27_bss_5194);
  lbl_27_bss_51F8 = 1;
 }
 return &lbl_27_bss_51FC;
}
extern "C" Obj* fn_27_1E10E0(Obj* self, soModuleAccesser* accesser, void* context, soEventObserverRegistrationDesc* registration, float scale) {
 self->calc = lbl_27_data_1EA88 + 0x48;
 self->vtable = lbl_27_data_1EA88;
 self->flags.raw &= 0x00ffffff;
 self->flags.bits.value = 5;
 self->flags.bits.flag = 0;
 soArrayVectorCalculator::postInitialize(*reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc), 5, 5);
 reinterpret_cast<soModelModuleImpl*>(reinterpret_cast<char*>(self) + 0x114)->__ct(accesser, reinterpret_cast<soArray<soModelNodeSetUp>*>(self), scale, context, reinterpret_cast<soArray<soModelVirtualNode>*>(getGlobal()), registration);
 return self;
}