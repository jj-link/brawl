#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_4D5C(void*, short);
extern "C" void* fn_101_522C(void*, short);

extern "C" void* fn_101_4CF0(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_4D5C(static_cast<unsigned char*>(object) + 0x2418, memberDeleting);
        fn_101_522C(static_cast<unsigned char*>(object) + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
