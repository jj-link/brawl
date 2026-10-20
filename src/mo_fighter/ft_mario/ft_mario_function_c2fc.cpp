#pragma force_active on
extern "C" {
void* fn_91_C29C(void*, short);
void* fn_91_C16C(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_C2FC(void* object, short deleting) {
    if (object != 0) {
        fn_91_C29C(static_cast<unsigned char*>(object) + 0x94,
                   static_cast<short>(-1));
        if (object != 0) {
            fn_91_C16C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
#pragma dont_inline reset
}
