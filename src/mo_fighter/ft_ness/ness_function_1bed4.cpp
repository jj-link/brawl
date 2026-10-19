#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_572C(void*, short);
void* fn_101_1BF44(void*, short);
}

extern "C" void* fn_101_1BED4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_572C(members + 0x1854, memberDeleting);
        fn_101_1BF44(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
