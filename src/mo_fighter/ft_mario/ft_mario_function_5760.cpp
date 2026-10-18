#pragma force_active on
extern "C" {
void* fn_91_19B8(void*, short);
void __dl__FPv(void*);

void* fn_91_5760(void* object, short deleting) {
    if (object != 0) {
        fn_91_19B8(static_cast<unsigned char*>(object) + 8, static_cast<short>(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
