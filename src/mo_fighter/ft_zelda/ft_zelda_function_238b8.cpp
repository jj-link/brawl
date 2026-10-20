#pragma force_active on
extern "C" {
void* fn_104_21D0(void*, short);
void* fn_104_226C(void*, short);
void* fn_104_22AC(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_104_238B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_21D0(members + 0xDC, memberDeleting);
        fn_104_226C(members + 0xC0, memberDeleting);
        fn_104_22AC(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
