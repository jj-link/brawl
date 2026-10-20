#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_95_675C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_66E4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x470, -1);
        if (object != 0) {
            fn_95_675C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
