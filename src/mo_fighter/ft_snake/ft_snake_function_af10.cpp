#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_122_AADC(void* self, unsigned char val);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

namespace {
struct ResourceStorage {
    void* vtable;
    unsigned int pad;
    void* context;
};
}

extern "C" void* fn_122_AF10(ResourceStorage* object, void*, void*, unsigned int kind, void* context) {
    fn_122_AADC(object, 0);
    object->vtable = lbl_27_data_2C030;
    object->context = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(reinterpret_cast<unsigned char*>(object) + 0xC, 0, object, kind);
    return object;
}
