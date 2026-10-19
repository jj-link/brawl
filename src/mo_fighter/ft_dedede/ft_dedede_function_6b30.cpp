#pragma force_active on
extern "C" void fn_117_66FC(void*, int);
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
    void*, unsigned long, void*, unsigned char);

extern "C" void* fn_117_6B30(void* object, int arg1, int arg2, unsigned char kind, void* resource) {
    fn_117_66FC(object, 0);
    *reinterpret_cast<unsigned char**>(object) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 8) = resource;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
        static_cast<unsigned char*>(object) + 0xC, 0, object, kind);
    return object;
}
