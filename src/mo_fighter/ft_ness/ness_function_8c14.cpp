#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_22A38(void*, short);
void* fn_27_1A2910(void*, short);
}

extern "C" void* fn_101_8C14(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_22A38(static_cast<unsigned char*>(object) + 0x34, memberDeleting);
        fn_27_1A2910(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
