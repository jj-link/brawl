#pragma force_active on
extern "C" {
void* fn_91_C760(void*, short);
void* fn_91_C628(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_C7C0(void* object, short deleting) {
    if (object != 0) {
        fn_91_C760(static_cast<unsigned char*>(object) + 0x17c, static_cast<short>(-1));
        if (object != 0) fn_91_C628(object, static_cast<short>(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
#pragma dont_inline reset
}
