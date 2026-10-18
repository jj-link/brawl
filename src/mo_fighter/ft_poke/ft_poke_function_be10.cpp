#pragma force_active on
void operator delete(void*);

extern "C" void fn_116_BDB0(void*, short);

extern "C" void* fn_116_BE10(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_BDB0(members + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
