#pragma force_active on
extern "C" {
void* fn_91_953C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_91_8870(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_9614(void* object, short deleting) {
    if (object != 0) {
        fn_91_953C(static_cast<unsigned char*>(object) + 0x2BEF4, static_cast<short>(-1));
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x2BEE4, static_cast<short>(-1));
        fn_91_8870(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
