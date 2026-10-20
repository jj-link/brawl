#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_122_2158(void*, short);
void* fn_122_21F4(void*, short);
void* fn_122_2234(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_122_3A20(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_122_2158(static_cast<unsigned char*>(object) + 0xDC, memberDeleting);
        fn_122_21F4(static_cast<unsigned char*>(object) + 0xC0, memberDeleting);
        fn_122_2234(static_cast<unsigned char*>(object) + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
