#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_125_20A8(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_125_2960(void*, short);
}

extern "C" void* fn_125_2024(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_125_20A8(storage + 0x1af60, memberDeleting);
        fn_27_C74E8(storage + 0x1af50, memberDeleting);
        fn_125_2960(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
