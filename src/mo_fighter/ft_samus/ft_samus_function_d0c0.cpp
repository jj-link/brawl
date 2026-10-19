#pragma force_active on
extern "C" void* fn_94_4750(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_D0C0(void* object, short baseDeleting)
{
    if (object != 0) {
        fn_94_4750(object, 0);
        if (baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
