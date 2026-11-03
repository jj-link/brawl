#pragma force_active on
#include <new>
#include <so/so_array_vector_calculator.h>
#include <so/model/so_model_module_impl.h>

extern "C" {
extern char lbl_27_data_1EA88[];
extern char lbl_27_data_3E3A8[];
void __ct__18soModelVirtualNodeFv(void*);
void __dt__18soModelVirtualNodeFv(void*, short);
void __construct_array(void*, void (*)(void*), void (*)(void*, short), unsigned long, int);
}

union NodeFlags {
    unsigned int raw;
    struct {
        unsigned int pad : 8;
        unsigned int size : 4;
        unsigned int rest : 20;
    } bits;
};

struct ModelStorage {
    void* vtable;
    void* calc;
    NodeFlags flags;
    char nodes[0x104];
    void* virtualVtable;
    void* virtualCalc;
    unsigned int top : 4;
    unsigned int size : 2;
    unsigned int full : 1;
    unsigned int rest : 25;
    char virtualNodes[0x14];
};

extern "C" ModelStorage* fn_27_314678(ModelStorage* self, soModuleAccesser* accesser, void* context, soEventObserverRegistrationDesc* registration, float scale) {
    self->vtable = lbl_27_data_1EA88;
    self->calc = lbl_27_data_1EA88 + 0x48;
    self->flags.raw &= 0x00ffffff;
    self->flags.bits.size = 5;
    self->flags.raw &= 0xfff7ffff;
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&self->calc, 5, 5);
    self->virtualVtable = lbl_27_data_3E3A8;
    self->virtualCalc = lbl_27_data_3E3A8 + 0x48;
    self->top = 0;
    self->size = 1;
    self->full = 0;
    __construct_array(self->virtualNodes, __ct__18soModelVirtualNodeFv, __dt__18soModelVirtualNodeFv, 0x14, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&self->virtualCalc, 1, 1);
    reinterpret_cast<soModelModuleImpl*>((char*)self + 0x130)->__ct(accesser, (soArray<soModelNodeSetUp>*)self, scale, context, (soArray<soModelVirtualNode>*)&self->virtualVtable, registration);
    return self;
}
