#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_104_1A34(void*, short);
void* fn_104_1E14(void*, short);
void* fn_104_1EB0(void*, short);
void* fn_104_17300(void*, short);
void fn_27_125E20(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_104_17260(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_1A34(members + 0x1febc, memberDeleting);
        fn_104_1E14(members + 0x1fa04, memberDeleting);
        fn_104_1EB0(members + 0x1f9c8, memberDeleting);
        fn_104_17300(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
