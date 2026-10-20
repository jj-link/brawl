#pragma force_active on
extern "C" {
void* fn_116_157DC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_116_15E08(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_15758(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_157DC(members + 0x145d4, memberDeleting);
        fn_27_C74E8(members + 0x145c4, memberDeleting);
        fn_116_15E08(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
