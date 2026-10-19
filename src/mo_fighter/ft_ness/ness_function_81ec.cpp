#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_B21D0(void*, short);
void* fn_27_CB4A0(void*, short);
}

extern "C" void* fn_101_81EC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_B21D0(static_cast<unsigned char*>(object) + 0x50, memberDeleting);
        if (object != 0) {
            fn_27_CB4A0(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
