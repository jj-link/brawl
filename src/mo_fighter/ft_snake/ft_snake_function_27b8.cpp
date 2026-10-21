#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_122_2158(void* p, short del);
void* fn_122_21F4(void* p, short n);
void* fn_122_2234(void* p, short flag);
void* fn_122_2850(void* p, short param);
void fn_27_1A6B04(void*, short);
}

extern "C" void* fn_122_27B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_122_2158(members + 0xA8C, memberDeleting);
        fn_122_21F4(members + 0xA70, memberDeleting);
        fn_122_2234(members + 0x9C4, memberDeleting);
        fn_122_2850(members + 0x4E0, memberDeleting);
        if (object != 0) {
            fn_27_1A6B04(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
