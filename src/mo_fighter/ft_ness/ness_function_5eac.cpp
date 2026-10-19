#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5F1C(void*, short);
void* fn_101_6280(void*, short);
}

extern "C" void* fn_101_5EAC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_5F1C(static_cast<unsigned char*>(object) + 0x1A570, memberDeleting);
        fn_101_6280(static_cast<unsigned char*>(object) + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
