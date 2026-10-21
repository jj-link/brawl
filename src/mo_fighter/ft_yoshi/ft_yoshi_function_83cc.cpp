#include <so/model/so_model_module_impl.h>
#pragma force_active on

extern "C" void* fn_27_19A7DC(void*, int, int);
extern "C" void* fn_27_CC75C(void*, int, int);

extern "C" void* fn_95_83CC(
    void* object, soModuleAccesser* accesser, float scale,
    void* context, soEventObserverRegistrationDesc* registration)
{
    unsigned char* storage = static_cast<unsigned char*>(object);
    fn_27_19A7DC(object, 8, 0);
    fn_27_CC75C(storage + 0x1AC, 3, 0);
    reinterpret_cast<soModelModuleImpl*>(storage + 0x1F4)->__ct(
        accesser,
        reinterpret_cast<soArray<soModelNodeSetUp>*>(object),
        scale,
        context,
        reinterpret_cast<soArray<soModelVirtualNode>*>(storage + 0x1AC),
        registration);
    return object;
}
