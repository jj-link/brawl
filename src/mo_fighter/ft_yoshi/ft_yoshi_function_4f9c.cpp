#pragma force_active on
extern "C" void* fn_95_22E0(void*, short);
extern "C" void* fn_95_237C(void*, short);
extern "C" void* fn_95_23BC(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_4F9C(void* object, short deleting) {
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
