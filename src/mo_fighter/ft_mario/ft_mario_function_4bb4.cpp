#pragma force_active on
extern "C" {
void* fn_27_1A1E70(void*, short);
void* fn_91_4B3C(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_4BB4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x190, static_cast<short>(-1));
        if (object != 0) fn_91_4B3C(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
