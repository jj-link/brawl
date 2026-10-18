#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_79_321C(void* object, int flags)
{
    if (object != 0) {
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
