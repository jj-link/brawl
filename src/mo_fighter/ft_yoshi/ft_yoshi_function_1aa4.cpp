#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_95_1B44(void*, short);
void* fn_95_1F24(void*, short);
void* fn_95_1FC0(void*, short);
void* fn_95_20F8(void*, short);
void fn_27_125E20(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_95_1AA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_95_1B44(members + 0x221cc, memberDeleting);
        fn_95_1F24(members + 0x21d14, memberDeleting);
        fn_95_1FC0(members + 0x21cd8, memberDeleting);
        fn_95_20F8(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
