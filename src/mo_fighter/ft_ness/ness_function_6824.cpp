#pragma force_active on
void operator delete(void*);

extern "C" void* fn_101_5F1C(void*, short);
extern "C" void* fn_101_6890(void*, short);

extern "C" void* fn_101_6824(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_101_5F1C(members + 0x1C20, memberDeleting);
        fn_101_6890(members + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
