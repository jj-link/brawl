#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_109_39C8(void* ptr, short count);

extern "C" void* fn_109_ADC0(void* object, short deleting) {
    if (object != 0) {
        fn_109_39C8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
