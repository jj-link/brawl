#pragma force_active on
extern "C" void fn_60_6470(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_60_668C(void* object, int count)
{
    if (object != 0) {
        fn_60_6470(object, 0);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
