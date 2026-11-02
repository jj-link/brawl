#include <so/model/so_model_module_impl.h>
#pragma force_active on

struct GlobalObject;

extern "C" {
extern char lbl_27_data_39618[];
extern int lbl_27_data_12498;
extern signed char lbl_27_bss_51F8;
extern char lbl_27_bss_84C0[];

void fn_27_82A94(void*, short);
void* __register_global_object(GlobalObject&, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_51FC;

static inline GlobalObject* getGlobal() {
    if (lbl_27_bss_51F8 == 0) {
        lbl_27_bss_51FC.vtable = 0;
        lbl_27_bss_51FC.vtable = &lbl_27_data_12498;
        __register_global_object(
            lbl_27_bss_51FC,
            (void*)fn_27_82A94,
            lbl_27_bss_84C0
        );
        lbl_27_bss_51F8 = 1;
    }
    return &lbl_27_bss_51FC;
}

union Flags {
    unsigned int raw;
    struct {
        unsigned int pad : 6;
        unsigned int value : 3;
        unsigned int flag : 1;
        unsigned int rest : 22;
    } bits;
};

struct Obj {
    void* vtable;
    void* calc;
    Flags flags;
};

extern "C" Obj* fn_27_37B99C(
    Obj* self,
    soModuleAccesser* accesser,
    void* context,
    soEventObserverRegistrationDesc* registration,
    float scale
) {
    self->vtable = lbl_27_data_39618;
    self->calc = lbl_27_data_39618 + 0x48;
    self->flags.raw &= 0x03ffffff;
    self->flags.bits.value = 3;
    self->flags.bits.flag = 0;

    soArrayVectorCalculator::postInitialize(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&self->calc), 3, 3
    );

    reinterpret_cast<soModelModuleImpl*>(
        reinterpret_cast<char*>(self) + 0xAC
    )->__ct(
        accesser,
        reinterpret_cast<soArray<soModelNodeSetUp>*>(self),
        scale,
        context,
        reinterpret_cast<soArray<soModelVirtualNode>*>(getGlobal()),
        registration
    );

    return self;
}
