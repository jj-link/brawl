#pragma force_active on
extern "C" {
void* fn_120_11EC4(void*, short);
void* fn_120_11E84(void*, short);
void* fn_120_11E44(void*, short);
void fn_120_13560(void*, short);
}

extern "C" void* fn_120_135E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_120_11EC4(members + 0x2028, memberDeleting);
        fn_120_11E84(members + 0x2024, memberDeleting);
        fn_120_11E44(members + 0x2020, memberDeleting);
        fn_120_13560(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
