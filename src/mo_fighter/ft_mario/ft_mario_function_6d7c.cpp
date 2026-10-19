#pragma force_active on
extern "C" {
void* fn_91_6CBC(void*, short);
void __dl__FPv(void*);

#pragma dont_inline on
void* fn_91_6D7C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) fn_91_6CBC(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
#pragma dont_inline reset
}
