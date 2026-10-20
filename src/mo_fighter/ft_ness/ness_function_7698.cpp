#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_41FC(void*, short);
void* fn_101_7710(void*, short);
void* fn_27_19E99C(void*, short);
}

extern "C" void* fn_101_7698(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_41FC(members + 0x85C, memberDeleting);
        fn_101_7710(members + 0x19C, memberDeleting);
        fn_27_19E99C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
