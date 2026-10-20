#pragma force_active on
extern "C" {
void* fn_27_D2904(void*, short);
void* fn_91_4E0C(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_4E84(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x318, static_cast<short>(-1));
        if (object != 0) fn_91_4E0C(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
