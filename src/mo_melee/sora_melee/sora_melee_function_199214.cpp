#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_199214(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        __dl__FPv(object);
    }
    return object;
}
