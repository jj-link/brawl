#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_112_7674(void* obj, unsigned char b);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_112_7AA8(void* object, void*, void*, unsigned char kind, void* context) {
    fn_112_7674(object, 0);
    *reinterpret_cast<unsigned char**>(object) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(static_cast<unsigned char*>(object) + 0xC, 0, object, kind);
    return object;
}
