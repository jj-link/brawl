#pragma force_active on
extern "C" void* fn_27_1966BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_84B0(void* object, short size) {
    if (object != 0) {
        fn_27_1966BC(object, -1);
        if (size > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
