#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_10424(void*, short);
void* fn_27_19A97C(void*, short);
}

extern "C" void* fn_101_3138(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_10424(static_cast<unsigned char*>(object) + 0x7C, memberDeleting);
        if (object != 0) {
            fn_27_19A97C(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
