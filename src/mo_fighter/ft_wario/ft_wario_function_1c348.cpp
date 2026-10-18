#pragma force_active on
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_1C348(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_1A241C(members + 0x10, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
