#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_21F0(void*, short);
void* fn_117_228C(void*, short);
void* fn_117_22CC(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_117_1EE88(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_21F0(members + 0xDC, memberDeleting);
        fn_117_228C(members + 0xC0, memberDeleting);
        fn_117_22CC(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
