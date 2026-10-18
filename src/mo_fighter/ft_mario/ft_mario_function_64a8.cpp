#pragma force_active on
extern "C" {
void* fn_91_46A8(void*, short);
void __dl__FPv(void*);

void* fn_91_64A8(void* object, short deleting) {
    if (object != 0) {
        fn_91_46A8(static_cast<unsigned char*>(object) + 0x38, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
