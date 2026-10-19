#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5994(void*, short);
void* fn_101_18C6C(void*, short);
}

extern "C" void* fn_101_18C00(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_5994(static_cast<unsigned char*>(object) + 0x1F8C, memberDeleting);
        fn_101_18C6C(static_cast<unsigned char*>(object) + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
