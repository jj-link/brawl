#pragma force_active on
extern "C" void __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_27_CBDE8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_48DC(void* object, short memberDeleting) {
    if (object != 0) {
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x114, -1);
        fn_27_CBDE8(object, -1);
        if (memberDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
