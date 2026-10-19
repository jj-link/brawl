#pragma force_active on
extern "C" unsigned char lbl_27_data_2C030[];
extern "C" void fn_107_8648(void* object, unsigned char isNull);
extern "C" void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);

struct Fn107Obj {
    void* vtable;
    void* context;
    unsigned char pad[0x0C - 0x08];
};

extern "C" void* fn_107_8A7C(void* object, void*, void*, unsigned char kind, void* context) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    fn_107_8648(object, 0);
    *reinterpret_cast<void**>(storage) = lbl_27_data_2C030;
    *reinterpret_cast<void**>(storage + 0x8) = context;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(storage + 0xC, 0, object, kind);
    return object;
}
