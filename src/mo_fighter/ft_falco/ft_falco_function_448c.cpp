#pragma force_active on
extern "C" {
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_CBDE8(void*, short);
void __dl__FPv(void*);
}

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_108_448C(void* object, short deleting) {
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
