#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_98_2138(void*, short);
void* fn_98_21D4(void*, short);
void* fn_98_2214(void*, short);
void* fn_27_C7770(void*, short);
}

static inline void destroyCommonBase(char* object, short deleting) {
    if (object) fn_27_C7770(object, deleting);
}

extern "C" void* fn_98_2680(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_2138(object + 0xdc, memberDeleting);
        fn_98_21D4(object + 0xc0, memberDeleting);
        fn_98_2214(object + 0x14, memberDeleting);
        destroyCommonBase(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
