#pragma force_active on
extern "C" {
void fn_91_6124(void*, short);
void __dl__FPv(void*);

void* fn_91_C1DC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) fn_91_6124(object, static_cast<short>(0));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
