#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5F1C(void*, short);
void* fn_101_67B8(void*, short);
}

extern "C" void* fn_101_674C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_5F1C(static_cast<unsigned char*>(object) + 0x5450, memberDeleting);
        fn_101_67B8(static_cast<unsigned char*>(object) + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
