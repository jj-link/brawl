#pragma force_active on
extern "C" void fn_120_5BD8(void*, unsigned char);
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_120_600C(void* object, int arg1, int arg2, unsigned char kind, void* resource) {
    fn_120_5BD8(object, 0);
    *reinterpret_cast<unsigned char**>(object) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 8) = resource;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
        static_cast<unsigned char*>(object) + 0xC, 0, object, kind);
    return object;
}
