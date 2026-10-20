#pragma force_active on
extern "C" void* fn_114_232C(void*, short);
extern "C" void* fn_114_23C8(void*, short);
extern "C" void* fn_114_2408(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_14948(void* object, short deleting) {
    void* result = object;
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_114_232C(members + 0xDC, memberDeleting);
        fn_114_23C8(members + 0xC0, memberDeleting);
        fn_114_2408(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return result;
}
