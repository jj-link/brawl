#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_48BE8(void*, short);
void* fn_27_4742C(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CDDE8(void*, short);
void* fn_27_CD78C(void*, short);
}

extern "C" void* fn_101_8894(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_48BE8(members + 0x1C4, memberDeleting);
        fn_27_4742C(members + 0x1B4, memberDeleting);
        fn_27_4CAA0(members + 0x130, memberDeleting);
        fn_27_CDDE8(members + 0x6C, memberDeleting);
        fn_27_CD78C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
