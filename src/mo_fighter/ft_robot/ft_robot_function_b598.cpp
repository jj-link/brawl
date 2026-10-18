#pragma force_active on
void operator delete(void*);

extern "C" void* fn_120_B538(void*, short);

extern "C" void* fn_120_B598(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_120_B538(members + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
