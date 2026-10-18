#pragma force_active on
extern "C" {
void* fn_91_C568(void*, short);
void __dl__FPv(void*);

void* fn_91_C5C8(void* object, short deleting) {
    if (object != 0) {
        fn_91_C568(static_cast<unsigned char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
