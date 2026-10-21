#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_21F0(void*, short);
void* fn_117_228C(void*, short);
void* fn_117_22CC(void*, short);
void* fn_117_28E8(void*, short);
void fn_27_1A6D0C(void*, short);
}

extern "C" void* fn_117_2850(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_21F0(members + 0xAB4, memberDeleting);
        fn_117_228C(members + 0xA98, memberDeleting);
        fn_117_22CC(members + 0x9EC, memberDeleting);
        fn_117_28E8(members + 0x4F4, memberDeleting);
        if (object != 0) {
            fn_27_1A6D0C(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
