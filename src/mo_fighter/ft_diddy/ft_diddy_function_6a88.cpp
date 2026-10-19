#pragma force_active on
extern "C" void fn_115_6654(void*, bool);
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

extern "C" void* fn_115_6A88(void* object, void*, void*, unsigned char kind, void* context) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    fn_115_6654(object, false);
    *reinterpret_cast<void**>(storage) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(storage + 8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(storage + 0xC, 0, object, kind);
    return object;
}
