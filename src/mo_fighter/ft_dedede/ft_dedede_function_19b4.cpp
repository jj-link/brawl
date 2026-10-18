#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_1A54(void*, short);
void* fn_117_1E34(void*, short);
void* fn_117_1ED0(void*, short);
void* fn_117_2008(void*, short);
void fn_27_125E20(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_117_19B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_1A54(members + 0x476c0, memberDeleting);
        fn_117_1E34(members + 0x47208, memberDeleting);
        fn_117_1ED0(members + 0x471cc, memberDeleting);
        fn_117_2008(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
