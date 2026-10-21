#pragma force_active on
extern "C" {
void* fn_113_D68(void*, short);
void* fn_113_E04(void*, short);
void* fn_113_E44(void*, short);
void* fn_113_EA0(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_113_14834(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_D68(members + 0xEC, memberDeleting);
        fn_113_E04(members + 0xD0, memberDeleting);
        fn_113_E44(members + 0x24, memberDeleting);
        fn_113_EA0(members + 0x10, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
