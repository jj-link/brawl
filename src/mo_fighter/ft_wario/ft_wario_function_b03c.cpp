#pragma force_active on
extern void operator delete(void*);

extern "C" void fn_110_AFDC(void*, short);

extern "C" void* fn_110_B03C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_AFDC(members + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
