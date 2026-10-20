#pragma force_active on
extern "C" void* fn_114_4150(void*, short);
extern "C" void* fn_114_6FE8(void*, short);
extern "C" void* fn_27_19E99C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_6F70(void* object, short deleting) {
    if (object != 0) {
        fn_114_4150((char*)object + 0x85C, -1);
        fn_114_6FE8((char*)object + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
