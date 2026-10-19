#include <so/model/so_model_module_impl.h>
#pragma force_active on

extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_113_7F94(void* obj, int value);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_113_8450(void* object, int, int, unsigned char kind, void* context) {
    fn_113_7F94(object, 0);
    void** storage = static_cast<void**>(object);
    storage[0] = lbl_27_data_2C030;
    storage[2] = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(reinterpret_cast<unsigned char*>(object) + 0xC, 0, object, kind);
    return object;
}
