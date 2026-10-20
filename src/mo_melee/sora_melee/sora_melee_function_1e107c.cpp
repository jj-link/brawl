#pragma force_active on
extern "C" unsigned char lbl_27_data_465C0[];
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
    void*, unsigned long, void*, unsigned char);

extern "C" void* fn_27_1E107C(void* object, unsigned long arg1, void* arg2, unsigned char kind) {
    unsigned char* p = (unsigned char*)object;
    *reinterpret_cast<void**>(p + 0x10) = arg2;
    p[4] = 0;
    *reinterpret_cast<void**>(p) = lbl_27_data_465C0;
    *reinterpret_cast<unsigned long*>(p + 8) = arg1;
    *reinterpret_cast<unsigned long*>(p + 0xC) = arg1;
    *reinterpret_cast<unsigned short*>(p + 0x14) = 0;
    *reinterpret_cast<unsigned short*>(p + 0x16) = 0;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(
        p + 0x18, 0, object, kind);
    return object;
}
