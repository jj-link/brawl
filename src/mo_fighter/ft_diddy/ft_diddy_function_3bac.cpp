#pragma force_active on
void operator delete(void*);

extern "C" void* fn_115_3C0C(void*, short);

extern "C" void* fn_115_3BAC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_115_3C0C(members + 0x0C, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
