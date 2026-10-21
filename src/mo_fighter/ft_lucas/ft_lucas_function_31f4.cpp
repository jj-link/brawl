#pragma force_active on
extern "C" void* fn_27_97968(void*, short);
extern "C" void* fn_27_1CCCC(void*, short);
extern "C" void* fn_114_328C(void*, short);
extern "C" void* fn_114_32E8(void*, short);
extern "C" void* fn_27_CBF58(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_31F4(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_27_97968((char*)object + 0x6C, memberDeleting);
        fn_27_1CCCC((char*)object + 0x5C, memberDeleting);
        fn_114_328C((char*)object + 0x50, memberDeleting);
        fn_114_32E8((char*)object + 0x38, memberDeleting);
        if (object != 0) {
            fn_27_CBF58(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
