#pragma force_active on
void operator delete(void*);

extern "C" {
void __dt__24soCollisionHitModuleImplFv(void*, short);
void* fn_27_CC984(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19AB9C(void*, short);
}

extern "C" void* fn_113_292A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        __dt__24soCollisionHitModuleImplFv(members + 0x13C, memberDeleting);
        fn_27_CC984(members + 0xF8, memberDeleting);
        fn_27_4CAA0(members + 0x74, memberDeleting);
        fn_27_19AB9C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
