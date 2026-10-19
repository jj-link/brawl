#pragma force_active on
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_CBDE8(void*, short);
extern "C" void __dl__FPv(void*);

// Release the embedded model module before the object itself, then free the
// storage when called through the scalar/deleting entry point (deleting > 0).
extern "C" void* fn_109_43E4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__17soModelModuleImplFv(storage + 0x114, -1);
        fn_27_CBDE8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
