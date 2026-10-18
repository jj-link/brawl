#pragma force_active on
extern "C" void* fn_27_C31CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_4CC4(void* object, short count) {
    if (object != 0) {
        fn_27_C31CC(object, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
