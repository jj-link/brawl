#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_98_5BB8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_5B40(void* object, short deleting) {
    if (object) {
        fn_27_1A15B8((char*)object + 0x470, short(-1));
        if (object) fn_98_5BB8(object, short(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
