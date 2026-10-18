#pragma force_active on
extern "C" void* fn_104_17F58(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_17EF8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_17F58(members + 4, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
