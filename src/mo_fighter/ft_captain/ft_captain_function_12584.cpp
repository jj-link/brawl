#pragma force_active on
extern "C" {
void* fn_100_37FC(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_100_1260C(char*, short);
void* fn_27_1D81C8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_12584(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_100_37FC(members + 0x209C, memberDeleting);
        fn_27_1DBB60(members + 0x2064, memberDeleting);
        fn_100_1260C(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
