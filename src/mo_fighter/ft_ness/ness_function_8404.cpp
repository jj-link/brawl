#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_565F0(void*, short);
void* fn_101_8470(void*, short);
}

extern "C" void* fn_101_8404(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, memberDeleting);
        fn_101_8470(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
