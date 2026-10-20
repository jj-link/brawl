#pragma force_active on
extern "C" {
void* fn_120_2060(void*, short);
void* fn_120_2918(void*, short);
void __dl__FPv(void*);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_120_1FDC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_120_2060(members + 0x1058C, memberDeleting);
        fn_27_C74E8(members + 0x1057C, memberDeleting);
        fn_120_2918(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
