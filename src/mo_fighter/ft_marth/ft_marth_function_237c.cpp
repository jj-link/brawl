#pragma force_active on
extern "C" {
void* fn_106_217C(void*, short);
void* fn_106_2218(void*, short);
void* fn_106_2258(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_106_237C(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_106_217C(members + 0xDC, memberDeleting);
        fn_106_2218(members + 0xC0, memberDeleting);
        fn_106_2258(members + 0x14, memberDeleting);
        if (object != 0)
            fn_27_C7770(object, memberDeleting);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
