#pragma force_active on
void operator delete(void*);

extern "C" void* fn_102_3A8C(void*, short);

extern "C" void* fn_102_1A6E4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_3A8C(members + 0x2C, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
