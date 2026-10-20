#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_2D0C(void*, short);
extern "C" void* fn_113_4A78(void*, short);
extern "C" void* fn_27_19E99C(void*, short);

extern "C" void* fn_113_4A00(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_2D0C(members + 0x85c, memberDeleting);
        fn_113_4A78(members + 0x19c, memberDeleting);
        fn_27_19E99C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
