#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_68_5674(void* object, int deleteFlag)
{
    if (object != 0) {
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
