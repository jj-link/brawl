#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5F1C(void*, short);
void* fn_101_6360(void*, short);
}

extern "C" void* fn_101_62F0(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_5F1C(static_cast<unsigned char*>(object) + 0x16D40, memberDeleting);
        fn_101_6360(static_cast<unsigned char*>(object) + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
