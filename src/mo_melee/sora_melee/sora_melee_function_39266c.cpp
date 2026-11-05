#include <so/model/so_model_module_impl.h>
#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_9AA08[];
extern int lbl_27_data_12498;
extern signed char lbl_27_bss_51F8;
extern char lbl_27_bss_887C[];
extern GlobalObject lbl_27_bss_51FC;

void fn_27_82A94(void*, short);
void* __register_global_object(void*, void*, void*);
}

union Flags {
    unsigned int raw;
    struct {
        unsigned int pad : 8;
        unsigned int value : 4;
        unsigned int flag : 1;
        unsigned int rest : 19;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

static inline GlobalObject* getGlobal() {
    if (lbl_27_bss_51F8 == 0) {
        lbl_27_bss_51FC.vtable = 0;
        lbl_27_bss_51FC.vtable = &lbl_27_data_12498;
        __register_global_object(&lbl_27_bss_51FC, (void*)fn_27_82A94, lbl_27_bss_887C);
        lbl_27_bss_51F8 = 1;
    }
    return &lbl_27_bss_51FC;
}

extern "C" Obj* fn_27_39266C(Obj* self, soModuleAccesser* accesser, void* context, soEventObserverRegistrationDesc* registration, float scale) {
    self->calc = lbl_27_data_9AA08 + 0x48;
    self->vtable = lbl_27_data_9AA08;
    self->flags.raw &= 0x00ffffff;
    self->flags.bits.value = 4;
    self->flags.bits.flag = 0;

    soArrayVectorCalculator::postInitialize(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc), 4, 4);

    reinterpret_cast<soModelModuleImpl*>(reinterpret_cast<char*>(self) + 0xE0)->__ct(
        accesser,
        reinterpret_cast<soArray<soModelNodeSetUp>*>(self),
        scale,
        context,
        reinterpret_cast<soArray<soModelVirtualNode>*>(getGlobal()),
        registration);

    return self;
}
