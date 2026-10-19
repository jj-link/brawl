#pragma force_active on
extern "C" void* fn_102_A7A0(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_A938(void* object, short param) {
    if (object != 0) {
        fn_102_A7A0(object, 0);
        if (param > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
