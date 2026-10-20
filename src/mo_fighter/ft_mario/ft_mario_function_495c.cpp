#pragma force_active on
extern "C" {
void* fn_27_D2904(void*, short);
void* fn_91_48E4(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_495C(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, static_cast<short>(-1));
        if (object != 0) {
            fn_91_48E4(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
#pragma dont_inline reset
}
