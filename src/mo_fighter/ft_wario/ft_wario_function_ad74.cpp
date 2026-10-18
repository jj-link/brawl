#pragma force_active on
extern "C" void* fn_110_AD14(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_110_AD74(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_AD14(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
