#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_3B4C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_101_1E178(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_101_1E0F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3B4C(members + 0x1B94, memberDeleting);
        fn_27_1DBB60(members + 0x1B5C, memberDeleting);
        fn_101_1E178(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
