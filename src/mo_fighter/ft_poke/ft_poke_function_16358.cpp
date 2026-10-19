#pragma force_active on
extern "C" {
void* fn_116_163C8(void*, short);
void* fn_116_16950(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_116_16358(void* object, short deleting) {
    if (object != 0) {
        fn_116_163C8(static_cast<unsigned char*>(object) + 0xCB60, static_cast<short>(-1));
        fn_116_16950(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
