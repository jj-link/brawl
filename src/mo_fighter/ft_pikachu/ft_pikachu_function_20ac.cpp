#pragma force_active on

extern "C" {
void* fn_98_2138(void*, short);
void* fn_98_21D4(void*, short);
void* fn_98_2214(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_20AC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        char* members = static_cast<char*>(object);
        fn_98_2138(members + 0xDC, memberDeleting);
        fn_98_21D4(members + 0xC0, memberDeleting);
        fn_98_2214(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
