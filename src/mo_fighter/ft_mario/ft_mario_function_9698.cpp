#pragma force_active on
extern "C" {
void* fn_91_1E48(void*, short);
void* fn_91_1AC4(void*, short);
void* fn_91_1938(void*, short);
void* fn_91_9614(void*, short);
void* fn_27_125E20(void*, short);
void* __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_9698(void* object, short deleting) {
    if (object != 0) {
        fn_91_1E48(static_cast<unsigned char*>(object) + 0x2DB28, static_cast<short>(-1));
        fn_91_1AC4(static_cast<unsigned char*>(object) + 0x2D670, static_cast<short>(-1));
        fn_91_1938(static_cast<unsigned char*>(object) + 0x2D634, static_cast<short>(-1));
        fn_91_9614(static_cast<unsigned char*>(object) + 0x194, static_cast<short>(-1));
        fn_27_125E20(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
