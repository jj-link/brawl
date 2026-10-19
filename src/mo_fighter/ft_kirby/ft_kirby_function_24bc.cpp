#pragma force_active on
extern "C" void* __dt__19soPostureModuleImplFv(void*, short);
extern "C" void* fn_27_19FFEC(void*, short);
void operator delete(void*);

extern "C" void* fn_96_24BC(void* object, short deleting) {
    if (object != 0) {
        __dt__19soPostureModuleImplFv(static_cast<unsigned char*>(object) + 0x3C, -1);
        if (object != 0) {
            fn_27_19FFEC(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
