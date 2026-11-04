#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_117_2164(void*, short);
void* fn_117_2328(void*, short);
void* fn_117_23F0(void*, short);
void* fn_117_247C(void*, short);
void* fn_117_2508(void*, short);
void* fn_117_2594(void*, short);
void* fn_117_2620(void*, short);
void* fn_117_26AC(void*, short);
void* fn_117_2738(void*, short);
void* fn_117_27C4(void*, short);
void* fn_117_2850(void*, short);
}

extern "C" void* fn_117_208C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_2164(members + 0x1588, memberDeleting);
        fn_117_2328(members + 0x1464, memberDeleting);
        fn_117_23F0(members + 0x1338, memberDeleting);
        fn_117_247C(members + 0x120C, memberDeleting);
        fn_117_2508(members + 0x10E0, memberDeleting);
        fn_117_2594(members + 0xFB4, memberDeleting);
        fn_117_2620(members + 0xE88, memberDeleting);
        fn_117_26AC(members + 0xD5C, memberDeleting);
        fn_117_2738(members + 0xC30, memberDeleting);
        fn_117_27C4(members + 0xB04, memberDeleting);
        fn_117_2850(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
