void operator delete(void*);
extern "C" {
void* fn_101_4784(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_101_4900(void*, short);
void* fn_101_4A6C(void*, short);
void* fn_101_155C4(void*, short);
}

extern "C" void* fn_101_15438(void* object, short deleting) {
    if (object != 0) {
        fn_101_4784(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_101_15494(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x9C, memberDeleting);
        fn_27_21038(static_cast<unsigned char*>(object) + 0x88, memberDeleting);
        fn_101_4900(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_101_1550C(void* object, short deleting) {
    if (object != 0) {
        fn_101_4A6C(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_101_15568(void* object, short deleting) {
    if (object != 0) {
        fn_101_155C4(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
