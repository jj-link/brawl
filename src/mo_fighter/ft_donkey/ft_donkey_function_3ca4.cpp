#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_3CA4(void* object, short flags) {
    if (object != 0 && flags > 0) {
        __dl__FPv(object);
    }
    return object;
}
