#pragma force_active on
extern "C" void fn_93_486C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_5B0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_93_486C(members + 0x1C0, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
