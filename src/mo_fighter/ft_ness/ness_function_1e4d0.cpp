#pragma force_active on
void operator delete(void*);
extern "C" {
void __dt__17soModelModuleImplFv(void*, short);
void* fn_27_19A5BC(void*, short);
}

extern "C" void* fn_101_1E4D0(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        __dt__17soModelModuleImplFv(static_cast<unsigned char*>(object) + 0x78, memberDeleting);
        fn_27_19A5BC(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
