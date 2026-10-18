#pragma force_active on
extern "C" {
void fn_120_1A28(void*, short);
void fn_120_1E08(void*, short);
void fn_120_1EA4(void*, short);
void fn_120_1FDC(void*, short);
void fn_27_125E20(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_1988(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_120_1A28(members + 0x121E8, memberDeleting);
        fn_120_1E08(members + 0x11D30, memberDeleting);
        fn_120_1EA4(members + 0x11CF4, memberDeleting);
        fn_120_1FDC(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
