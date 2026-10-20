#pragma force_active on
extern "C" {
void* fn_122_2158(void*, short);
void* fn_122_21F4(void*, short);
void* fn_122_2234(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_122_24FC(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_122_2158(members + 0xDC, memberDeleting);
        fn_122_21F4(members + 0xC0, memberDeleting);
        fn_122_2234(members + 0x14, memberDeleting);
        if (object) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
