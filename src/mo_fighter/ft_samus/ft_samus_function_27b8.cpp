#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_94_2158(void*, short);
void* fn_94_21F4(void*, short);
void* fn_94_2234(void*, short);
void* fn_94_2850(void*, short);
void* fn_27_1A67F8(void*, short);
}

extern "C" void* fn_94_27B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_2158(members + 0xA4C, memberDeleting);
        fn_94_21F4(members + 0xA30, memberDeleting);
        fn_94_2234(members + 0x984, memberDeleting);
        fn_94_2850(members + 0x4C0, memberDeleting);
        if (object != 0) {
            fn_27_1A67F8(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
