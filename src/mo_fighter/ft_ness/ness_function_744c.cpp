#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_D84C(void*, short);
void* fn_101_74C4(void*, short);
void* fn_101_7534(void*, short);
}

extern "C" void* fn_101_744C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_D84C(static_cast<unsigned char*>(object) + 0xE0, memberDeleting);
        fn_101_74C4(static_cast<unsigned char*>(object) + 0x30, memberDeleting);
        fn_101_7534(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
