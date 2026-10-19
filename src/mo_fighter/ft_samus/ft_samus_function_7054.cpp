#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_94_6C20(void* obj, unsigned char val);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void* self, unsigned long id, void* accesser, unsigned char kind);

extern "C" void* fn_94_7054(void* obj, void* unused1, void* unused2, unsigned char kind, void* context) {
    unsigned char* self = static_cast<unsigned char*>(obj);
    fn_94_6C20(obj, 0);
    *reinterpret_cast<unsigned char**>(self) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(self + 0x8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(self + 0xC, 0, obj, kind);
    return obj;
}
