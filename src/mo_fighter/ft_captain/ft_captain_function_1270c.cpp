#pragma force_active on
extern "C" {
void* fn_100_2158(void*, short);
void* fn_100_21F4(void*, short);
void* fn_100_2234(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_1270C(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_100_2158(members + 0xDC, memberDeleting);
        fn_100_21F4(members + 0xC0, memberDeleting);
        fn_100_2234(members + 0x14, memberDeleting);
        if (object != 0)
            fn_27_C7770(object, memberDeleting);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
