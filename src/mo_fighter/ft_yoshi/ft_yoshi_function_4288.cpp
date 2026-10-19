#pragma force_active on
extern "C" void* fn_27_A1E80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_4288(void* object, int destroy) {
    if (object != 0) {
        fn_27_A1E80(object, -1);
        if (static_cast<short>(destroy) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
