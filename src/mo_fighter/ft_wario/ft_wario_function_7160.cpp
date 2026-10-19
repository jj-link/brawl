#include <new>
#pragma force_active on

extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_110_6D2C(void* obj, unsigned char flag);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

namespace {
struct ResourceStorage {
    void* vtable;
    unsigned char flag;
    unsigned char padding[3];
    void* context;
};
}

extern "C" void* fn_110_7160(ResourceStorage* object, void*, void*, unsigned char flag, void* context) {
    fn_110_6D2C(object, 0);
    object->vtable = lbl_27_data_2C030;
    object->context = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(reinterpret_cast<unsigned char*>(object) + 0xC, 0, object, flag);
    return object;
}
