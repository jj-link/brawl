#pragma force_active on
extern "C" void* fn_109_A8FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_AA94(void* object, short deleting) {
    if (object != 0) {
        short zero = 0;
        fn_109_A8FC(object, zero);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
