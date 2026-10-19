#pragma force_active on
extern "C" void* __dt__20soResourceModuleImplFv(void*, short);
extern "C" void* fn_105_7E58(void*, short);
void operator delete(void*);

extern "C" void* fn_105_7DEC(void* object, short deleting) {
    if (object != 0) {
        __dt__20soResourceModuleImplFv(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_105_7E58(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
