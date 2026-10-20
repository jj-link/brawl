#pragma force_active on
void operator delete(void*);

extern "C" {
void __dt__17soModelModuleImplFv(void*, short);
void* fn_98_7100(void*, short);
void* fn_27_19A83C(void*, short);
}

extern "C" void* fn_98_7088(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        __dt__17soModelModuleImplFv(static_cast<char*>(object) + 0x1f4, memberDeleting);
        fn_98_7100(static_cast<char*>(object) + 0x1ac, memberDeleting);
        fn_27_19A83C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
