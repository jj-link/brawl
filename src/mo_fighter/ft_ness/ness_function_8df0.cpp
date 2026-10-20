#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_41FC(void*, short);
void* fn_101_8E68(void*, short);
void* fn_27_CD934(void*, short);
}

extern "C" void* fn_101_8DF0(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_41FC(static_cast<unsigned char*>(object) + 0xAC, memberDeleting);
        fn_101_8E68(static_cast<unsigned char*>(object) + 0x20, memberDeleting);
        fn_27_CD934(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
