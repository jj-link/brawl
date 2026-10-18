#pragma force_active on
extern "C" void fn_100_5168(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_5108(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_100_5168(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
