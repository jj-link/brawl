#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_48BE8(void*, short);
void* fn_27_47CCC(void*, short);
void* fn_27_CB800(void*, short);
void* fn_27_19FB24(void*, short);
void* fn_27_19E5E0(void*, short);
}

extern "C" void* fn_117_5B38(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_48BE8(members + 0xA14, memberDeleting);
        fn_27_47CCC(members + 0xA04, memberDeleting);
        fn_27_CB800(members + 0x908, memberDeleting);
        fn_27_19FB24(members + 0x78C, memberDeleting);
        fn_27_19E5E0(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
