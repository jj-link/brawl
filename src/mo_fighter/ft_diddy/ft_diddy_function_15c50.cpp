#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_1A262C(void*, short);

extern "C" void* fn_115_15C50(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_1A262C(members + 0x10, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
