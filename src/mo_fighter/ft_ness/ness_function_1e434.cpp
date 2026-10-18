#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_4090(void*, short);
void* fn_101_4114(void*, short);
void* fn_101_5BD4(void*, short);
void* fn_101_4174(void*, short);
void* fn_101_51CC(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_101_1E434(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_4090(members + 0x110, memberDeleting);
        fn_101_4114(members + 0xfc, memberDeleting);
        fn_101_5BD4(members + 0xec, memberDeleting);
        fn_101_4174(members + 0x48, memberDeleting);
        fn_101_51CC(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
