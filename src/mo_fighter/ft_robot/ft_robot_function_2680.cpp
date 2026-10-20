#pragma force_active on
extern "C" void* fn_120_21C4(void* object, short deleting);
extern "C" void* fn_120_2260(void* p, short flags);
extern "C" void* fn_120_22A0(void* object, short count);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_2680(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_120_21C4(members + 0xdc, memberDeleting);
        fn_120_2260(members + 0xc0, memberDeleting);
        fn_120_22A0(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
