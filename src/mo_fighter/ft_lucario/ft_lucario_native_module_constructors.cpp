#include <new>
#include <so/model/so_model_module_impl.h>

extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void* fn_118_6C2C(void*, unsigned int);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);
extern "C" void* fn_27_19A7DC(void*, int, int);
extern "C" void* fn_27_CC75C(void*, int, int);

namespace {
struct ResourceStorage {
    void* vtable;
    unsigned char flag;
    unsigned char padding[3];
    void* context;
};
}

extern "C" void* fn_118_7060(ResourceStorage* object, void*, void*, unsigned int kind, void* context) {
    fn_118_6C2C(object, 0);
    object->vtable = lbl_27_data_2C030;
    object->context = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(reinterpret_cast<unsigned char*>(object) + 0xC, 0, object, kind);
    return object;
}

extern "C" void* fn_118_70C8(void* object, soModuleAccesser* accesser, float scale, void* context, soEventObserverRegistrationDesc* registration) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    fn_27_19A7DC(object, 8, 0);
    fn_27_CC75C(storage + 0x1AC, 3, 0);
    new (storage + 0x1F4) soModelModuleImpl(accesser, reinterpret_cast<soArray<soModelNodeSetUp>*>(object), scale, context, reinterpret_cast<soArray<soModelVirtualNode>*>(storage + 0x1AC), registration);
    return object;
}
