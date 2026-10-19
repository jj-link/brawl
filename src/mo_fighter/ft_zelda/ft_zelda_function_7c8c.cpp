#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_104_7858(void* obj, unsigned char kind);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_104_7C8C(void* object, void*, void*, unsigned int kind, void* context) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    fn_104_7858(object, 0);
    *reinterpret_cast<unsigned char**>(storage) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(storage + 8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(storage + 0xC, 0, object, (unsigned char)kind);
    return object;
}
