#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_4090(void*, short);
void* fn_101_4114(void*, short);
void* fn_101_763C(void*, short);
void* fn_101_7698(void*, short);
void* fn_101_80B0(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_101_75A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_4090(members + 0xDD4, memberDeleting);
        fn_101_4114(members + 0xDC0, memberDeleting);
        fn_101_763C(members + 0x930, memberDeleting);
        fn_101_7698(members + 0xBC, memberDeleting);
        fn_101_80B0(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
