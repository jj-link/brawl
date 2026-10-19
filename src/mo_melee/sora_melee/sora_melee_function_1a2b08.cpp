#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1A2B08(void* object, short flag) {
    if (object != 0 && flag > 0) {
        __dl__FPv(object);
    }
    return object;
}
