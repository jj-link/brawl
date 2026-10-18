#pragma force_active on
extern "C" void* fn_116_BE10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_BE70(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_BE10(members + 8, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
