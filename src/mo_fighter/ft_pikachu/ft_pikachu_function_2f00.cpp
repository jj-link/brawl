#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_CB048(void*, short);
void* fn_27_199214(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_14E050(void*, short);
void* fn_27_197EF4(void*, short);
}

extern "C" void* fn_98_2F00(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_CB048((char*)object + 0x220, memberDeleting);
        fn_27_199214((char*)object + 0x94, memberDeleting);
        fn_27_A78FC((char*)object + 0x78, memberDeleting);
        fn_27_14E050((char*)object + 0x10, memberDeleting);
        if (object) fn_27_197EF4(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
