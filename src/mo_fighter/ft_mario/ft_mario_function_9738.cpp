#pragma force_active on
extern "C" {
void* fn_27_C74E8(void*, short);
void* fn_91_9698(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_9738(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x2DBD8, static_cast<short>(-1));
        fn_91_9698(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
