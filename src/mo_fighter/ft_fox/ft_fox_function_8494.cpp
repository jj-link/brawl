#include <new>
#pragma force_active on

extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_97_8060(void* object, bool isNull);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

namespace {
struct ResourceStorage {
    void* vtable;
    unsigned char flag;
    unsigned char padding[3];
    void* context;
};
}

extern "C" void* fn_97_8494(ResourceStorage* object, void*, void*, unsigned int kind, void* context) {
    fn_97_8060(object, false);
    object->vtable = lbl_27_data_2C030;
    object->context = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(reinterpret_cast<unsigned char*>(object) + 0xC, 0, object, kind);
    return object;
}
