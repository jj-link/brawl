#pragma force_active on
extern "C" {
void fn_98_7374(void*, unsigned char);
extern unsigned char lbl_27_data_2C030[];
void __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
    void*, unsigned long, void*, unsigned char);
}

extern "C" void* fn_98_77A8(
    void* object, unsigned long arg1, unsigned long arg2,
    unsigned long kind, void* resourceIdAccesser) {
    fn_98_7374(object, 0);
    *reinterpret_cast<unsigned char**>(object) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 8) = resourceIdAccesser;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
        static_cast<unsigned char*>(object) + 0xC, 0, object,
        static_cast<unsigned char>(kind));
    return object;
}
