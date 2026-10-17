void operator delete(void*);
extern "C" {
void* fn_27_13C90(void*, short);
void* fn_101_8C14(void*, short);
void* fn_27_21038(void*, short);
void* fn_101_8C80(void*, short);
void* fn_101_8CDC(void*, short);
void* fn_101_8D38(void*, short);
void* fn_101_8D94(void*, short);
void* fn_101_8DF0(void*, short);
}

extern "C" void* fn_101_8B60(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x224, memberDeleting);
        fn_101_8C14(static_cast<unsigned char*>(object) + 0x1E8, memberDeleting);
        fn_27_21038(static_cast<unsigned char*>(object) + 0x1D8, memberDeleting);
        fn_101_8C80(static_cast<unsigned char*>(object) + 0x1B8, memberDeleting);
        fn_101_8CDC(static_cast<unsigned char*>(object) + 0x198, memberDeleting);
        fn_101_8D38(static_cast<unsigned char*>(object) + 0x160, memberDeleting);
        fn_101_8D94(static_cast<unsigned char*>(object) + 0xC4, memberDeleting);
        fn_101_8DF0(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
