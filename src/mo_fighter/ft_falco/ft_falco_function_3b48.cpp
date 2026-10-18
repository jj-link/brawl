#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_3B48(void* object, int flag) {
    if (object != 0 && (short)flag > 0) {
        __dl__FPv(object);
    }
    return object;
}
