#pragma force_active on
extern "C" {
void* fn_91_C50C(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_C568(void* object, short deleting) {
    if (object != 0) {
        fn_91_C50C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
#pragma dont_inline reset
}
