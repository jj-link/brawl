#pragma force_active on
extern "C" {
void fn_100_6B88(void*, int);
extern unsigned char lbl_27_data_2C030[];
void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
    void*, unsigned long, void*, unsigned char);
}

extern "C" void* fn_100_6FBC(
    void* object, unsigned long arg1, unsigned long arg2,
    unsigned long kind, void* resourceIdAccesser) {
    fn_100_6B88(object, 0);
    *reinterpret_cast<unsigned char**>(object) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(object) + 8) =
        resourceIdAccesser;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
        reinterpret_cast<unsigned char*>(object) + 0xC, 0, object,
        static_cast<unsigned char>(kind));
    return object;
}
