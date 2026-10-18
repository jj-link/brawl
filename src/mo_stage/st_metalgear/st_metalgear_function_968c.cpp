#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_71_968C(void* object, int size)
{
    if (object != 0 && size > 0) {
        __dl__FPv(object);
    }
    return object;
}
