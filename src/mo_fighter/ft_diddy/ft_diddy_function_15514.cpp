#pragma force_active on
void operator delete(void*);
extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_CBDE8(void*, short);

extern "C" void* fn_115_15514(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(storage + 0x114, -1);
        fn_27_CBDE8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
