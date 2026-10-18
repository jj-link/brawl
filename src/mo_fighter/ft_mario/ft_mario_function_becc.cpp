#pragma force_active on
extern "C" {
void fn_91_BE6C(void*, short);
void __dl__FPv(void*);

void* fn_91_BECC(void* object, short deleting) {
    if (object != 0) {
        fn_91_BE6C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
