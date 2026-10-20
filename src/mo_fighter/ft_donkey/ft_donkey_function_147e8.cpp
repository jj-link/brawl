#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_92_2204(void*, short);
void* fn_92_22A0(void*, short);
void* fn_92_22E0(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_92_147E8(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_92_2204(static_cast<unsigned char*>(object) + 0xDC, memberDeleting);
        fn_92_22A0(static_cast<unsigned char*>(object) + 0xC0, memberDeleting);
        fn_92_22E0(static_cast<unsigned char*>(object) + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
