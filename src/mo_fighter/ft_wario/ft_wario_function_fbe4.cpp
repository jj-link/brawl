#pragma force_active on
void operator delete(void*);

extern "C" void* fn_110_FC44(void*, short);

extern "C" void* fn_110_FBE4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_FC44(members + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
