#pragma force_active on
void operator delete(void*);

extern "C" {
void* __dt__17soModelModuleImplFv(void*, short);
void* fn_27_CBDE8(void*, short);
}

extern "C" void* fn_98_4A74(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        __dt__17soModelModuleImplFv(static_cast<char*>(object) + 0x114, memberDeleting);
        fn_27_CBDE8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
