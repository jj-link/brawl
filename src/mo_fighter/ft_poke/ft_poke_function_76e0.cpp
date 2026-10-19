#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_116_72AC(void* obj, int kind);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_116_76E0(unsigned char* obj, int unused1, int unused2, unsigned char kind, void* context) {
    fn_116_72AC(obj, 0);
    *reinterpret_cast<void**>(obj) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(obj + 8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(obj + 0xC, 0, obj, kind);
    return obj;
}
