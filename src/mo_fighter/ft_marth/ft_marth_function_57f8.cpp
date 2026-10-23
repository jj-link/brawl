#pragma force_active on
extern "C" {
void fn_106_53C4(void*, int);
extern unsigned char lbl_27_data_2C030[];
void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
    void*, unsigned long, void*, unsigned char);
}

extern "C" void* fn_106_57F8(
    void* object, unsigned long arg1, unsigned long arg2,
    unsigned char kind, void* resource) {
    fn_106_53C4(object, 0);
    *reinterpret_cast<unsigned char**>(object) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 8) = resource;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
        static_cast<unsigned char*>(object) + 0xC, 0, object, kind);
    return object;
}
