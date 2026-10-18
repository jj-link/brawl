#pragma force_active on
extern "C" void fn_124_A084(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_A0E0(void* object, short shouldDelete)
{
    if (object != 0) {
        fn_124_A084((char*)object + 4, (short)-1);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
