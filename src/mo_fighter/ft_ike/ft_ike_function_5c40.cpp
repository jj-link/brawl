#include <new>
#pragma force_active on

extern "C" void fn_119_580C(void* object, int value);
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_119_5C40(void* object, void* unused1, void* unused2, unsigned char kind, void* context) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    fn_119_580C(object, 0);
    *reinterpret_cast<void**>(storage) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(storage + 8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(storage + 0xC, 0, object, kind);
    return object;
}
