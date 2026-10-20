#pragma force_active on
extern "C" {
void* fn_104_206C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_104_2924(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_104_1FE8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_206C(members + 0x1696C, memberDeleting);
        fn_27_C74E8(members + 0x1695C, memberDeleting);
        fn_104_2924(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
