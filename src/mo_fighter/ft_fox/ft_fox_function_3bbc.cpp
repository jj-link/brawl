#pragma force_active on
extern "C" void fn_97_3C1C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_3BBC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_97_3C1C(members + 0x38, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
