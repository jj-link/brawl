#pragma force_active on
extern "C" void __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_105_48D8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_4860(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__20soResourceModuleImplFv(storage + 0x18, -1);
        if (object != 0) {
            fn_105_48D8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
