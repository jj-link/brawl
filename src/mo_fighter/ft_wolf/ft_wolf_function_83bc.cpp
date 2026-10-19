#pragma force_active on
extern "C" void fn_125_7F88(void* self, unsigned char v);
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_125_83BC(void* object, void*, void*, unsigned char kind, void* context) {
    fn_125_7F88(object, 0);
    unsigned char* storage = static_cast<unsigned char*>(object);
    *reinterpret_cast<unsigned char**>(storage) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(storage + 8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(storage + 0xC, 0, object, kind);
    return object;
}
