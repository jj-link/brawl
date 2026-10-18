#pragma force_active on
extern "C" {
void* fn_91_C1DC(void*, short);
void __dl__FPv(void*);

void* fn_91_C23C(void* object, short deleting) {
    if (object != 0) {
        fn_91_C1DC(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
