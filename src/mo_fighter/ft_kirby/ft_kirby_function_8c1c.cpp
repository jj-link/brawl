#pragma force_active on
void operator delete(void*);

extern "C" void* fn_96_4E2C(void*, short);

extern "C" void* fn_96_8C1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_96_4E2C(members + 0x14, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
