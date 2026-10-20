#pragma force_active on
extern "C" {
void fn_101_9210(void*, int);
void __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);
}
extern "C" unsigned char lbl_27_data_2C030[];

extern "C" void* fn_101_9644(void* object, int unused1, int unused2, unsigned char flag, void* value) {
    fn_101_9210(object, 0);
    *static_cast<unsigned char**>(object) = lbl_27_data_2C030;
    static_cast<void**>(object)[2] = value;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(static_cast<unsigned char*>(object) + 0xC, 0, object, flag);
    return object;
}
