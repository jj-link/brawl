#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_7480(void* obj, short release) {
    if (obj != 0 && release > 0) {
        __dl__FPv(obj);
    }
    return obj;
}
