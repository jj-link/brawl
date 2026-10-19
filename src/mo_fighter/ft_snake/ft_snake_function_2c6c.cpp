#pragma force_active on
extern "C" void fn_27_C21DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_2C6C(void* object, short should_delete) {
    if (object != 0) {
        fn_27_C21DC(object, -1);
        if (should_delete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
