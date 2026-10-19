#pragma force_active on
extern "C" void fn_94_D3E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_D57C(void* object, short deleting) {
    if (object != 0) {
        fn_94_D3E4(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
