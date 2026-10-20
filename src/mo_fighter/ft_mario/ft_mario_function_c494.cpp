#pragma force_active on
extern "C" {
void* fn_91_C434(void*, short);
void* fn_91_C2FC(void*, short);

#pragma dont_inline on
void* fn_91_C494(void* object, short deleting) {
    if (object != 0) {
        fn_91_C434(static_cast<unsigned char*>(object) + 0xec, static_cast<short>(-1));
        if (object != 0) fn_91_C2FC(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
