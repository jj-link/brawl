#pragma force_active on
extern "C" void* fn_104_17E0C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_17DB0(void* object, short deleting) {
    if (object != 0) {
        fn_104_17E0C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
