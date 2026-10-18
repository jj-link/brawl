#pragma force_active on
extern "C" void* fn_27_ACC5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_2EFC(void* object, short count) {
    if (object != 0) {
        fn_27_ACC5C(object, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
