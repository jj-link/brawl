#pragma force_active on
extern "C" void* fn_27_1966BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_2CBC(void* object, short count) {
    if (object != 0) {
        fn_27_1966BC(object, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
