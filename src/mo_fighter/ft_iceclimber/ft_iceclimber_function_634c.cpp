#pragma force_active on
void operator delete(void*);

extern "C" void* fn_105_3C24(void*, short);

extern "C" void* fn_105_634C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_105_3C24(members + 0x19C, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
