#pragma force_active on
void operator delete(void*);

extern "C" void fn_96_11D48(void*, short);

extern "C" void* fn_96_11DA8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_96_11D48(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
