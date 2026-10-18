#pragma force_active on
extern "C" {
void* fn_91_21B8(void*, short);
void __dl__FPv(void*);

void* fn_91_21F8(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) fn_91_21B8(object, static_cast<short>(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
