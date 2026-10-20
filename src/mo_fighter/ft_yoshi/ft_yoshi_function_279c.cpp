#pragma force_active on
extern "C" {
void* fn_95_22E0(void* p, short flag);
void* fn_95_237C(void* p, short flag);
void* fn_95_23BC(void* p, short flag);
void* fn_27_C7770(void* p, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_95_279C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_95_22E0(members + 0xdc, memberDeleting);
        fn_95_237C(members + 0xc0, memberDeleting);
        fn_95_23BC(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
