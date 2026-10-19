#pragma force_active on
extern "C" void* fn_99_60A0(void*, unsigned char);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);
extern "C" unsigned char lbl_27_data_2C030[];

extern "C" void* fn_99_64D4(void* object, unsigned long unused, void* unused2, unsigned char kind, int value) {
    fn_99_60A0(object, 0);
    static_cast<void**>(object)[0] = lbl_27_data_2C030;
    static_cast<int*>(object)[2] = value;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(static_cast<unsigned char*>(object) + 0xC, 0, object, kind);
    return object;
}
