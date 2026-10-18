#pragma force_active on
extern "C" {
void* fn_91_2C5C(void*, short);
void __dl__FPv(void*);

void* fn_91_2C9C(void* object, short deleting) {
    if (object != 0) {
        fn_91_2C5C(static_cast<unsigned char*>(object) + 0x0C, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
