#pragma force_active on
extern "C" {
void* fn_120_21C4(void*, short);
void* fn_120_2260(void*, short);
void* fn_120_22A0(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_159BC(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_120_21C4(static_cast<char*>(object) + 0xdc, memberDeleting);
        fn_120_2260(static_cast<char*>(object) + 0xc0, memberDeleting);
        fn_120_22A0(static_cast<char*>(object) + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
