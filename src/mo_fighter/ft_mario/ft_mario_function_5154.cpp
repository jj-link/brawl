#pragma force_active on
extern "C" {
void* fn_91_50DC(void*, short);
void __dl__FPv(void*);

void* fn_91_5154(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_91_50DC(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
