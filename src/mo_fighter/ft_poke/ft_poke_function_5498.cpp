#pragma force_active on
void operator delete(void*);

extern "C" void* fn_116_3ACC(void*, short);

extern "C" void* fn_116_5498(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_3ACC(members + 0x1C0, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
