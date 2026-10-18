#pragma force_active on
void operator delete(void*);

extern "C" void* fn_113_1C6D0(void*, short);

extern "C" void* fn_113_1C730(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_1C6D0(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
