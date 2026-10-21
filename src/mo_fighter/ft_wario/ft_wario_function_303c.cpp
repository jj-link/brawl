#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_CA210(void*, short);
void* fn_27_199214(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_14E050(void*, short);
void* fn_27_197EF4(void*, short);
}

extern "C" void* fn_110_303C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_CA210(members + 0x220, memberDeleting);
        fn_27_199214(members + 0x94, memberDeleting);
        fn_27_A78FC(members + 0x78, memberDeleting);
        fn_27_14E050(members + 0x10, memberDeleting);
        if (object != 0) {
            fn_27_197EF4(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
