#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_17340(void*, short);

extern "C" void* fn_123_173A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_123_17340(members + 8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
