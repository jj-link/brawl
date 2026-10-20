#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_97968(void*, short);
void* fn_27_1CCCC(void*, short);
void* fn_101_3338(void*, short);
void* fn_27_CBF58(void*, short);
}

extern "C" void* fn_101_3D28(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_97968(static_cast<unsigned char*>(object) + 0x58, memberDeleting);
        fn_27_1CCCC(static_cast<unsigned char*>(object) + 0x48, memberDeleting);
        fn_101_3338(static_cast<unsigned char*>(object) + 0x3C, memberDeleting);
        if (object != 0) {
            fn_27_CBF58(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
