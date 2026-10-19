#pragma force_active on
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_CBDE8(void*, short);
extern "C" void __dl__FPv(void*);

// Release the embedded soModelModuleImpl member before the base, freeing storage if requested.
extern "C" void* fn_116_261A4(void* object, short deleting) {
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
