#pragma force_active on
extern "C" void fn_124_9F4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9FAC(void* object, short destroyFlag)
{
    if (object != 0) {
        fn_124_9F4C((char*)object + 8, (short)-1);
        if (destroyFlag > 0)
            __dl__FPv(object);
    }
    return object;
}
