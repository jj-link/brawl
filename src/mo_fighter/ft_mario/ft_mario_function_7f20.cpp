#pragma force_active on
extern "C" {
void* fn_91_7EC4(void*, short);
void* fn_91_5CC4(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_7F20(void* object, short deleting) {
    if (object != 0) {
        fn_91_7EC4(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        fn_91_5CC4(object, static_cast<short>(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
#pragma dont_inline reset
}
