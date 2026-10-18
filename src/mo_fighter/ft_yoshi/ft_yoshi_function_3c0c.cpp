#pragma force_active on
void operator delete(void*);

extern "C" void fn_95_3C6C(void*, short);

extern "C" void* fn_95_3C0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_95_3C6C(members + 0x38, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
