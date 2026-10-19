#pragma force_active on
extern "C" {
void* fn_120_57F0(void* object, short deleting);
void __dl__FPv(void* ptr);
}

extern "C" void* fn_120_5794(void* object, short deleting) {
    if (object != 0) {
        fn_120_57F0(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
