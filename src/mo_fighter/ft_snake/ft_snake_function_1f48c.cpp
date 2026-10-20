#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_122_2158(void* p, short del);
void* fn_122_21F4(void* p, short n);
void* fn_122_2234(void* p, short flag);
void* fn_27_C7770(void* p, short del);
}

extern "C" void* fn_122_1F48C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_122_2158(members + 0xDC, memberDeleting);
        fn_122_21F4(members + 0xC0, memberDeleting);
        fn_122_2234(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
