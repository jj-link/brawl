#pragma force_active on
void operator delete(void*);
extern "C" {
void* __dt__20soResourceModuleImplFv(void*, short);
void* fn_101_4A6C(void*, short);
}

extern "C" void* fn_101_8FF8(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0xC, static_cast<short>(-1));
        if (object != 0) {
            fn_101_4A6C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
