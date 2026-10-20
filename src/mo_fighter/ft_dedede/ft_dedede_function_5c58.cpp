#pragma force_active on
void operator delete(void*);

extern "C" void __dt__24soCollisionHitModuleImplFv(void*, short);
extern "C" void* fn_27_CC984(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_19B704(void*, short);

extern "C" void* fn_117_5C58(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        __dt__24soCollisionHitModuleImplFv(members + 0x8F4, memberDeleting);
        fn_27_CC984(members + 0x8B0, memberDeleting);
        fn_27_4CAA0(members + 0x82C, memberDeleting);
        fn_27_19B704(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
