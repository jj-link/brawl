#pragma force_active on
extern "C" void* fn_27_5BFA0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_2BA8(void* object, short count) {
    if (object != 0) {
        fn_27_5BFA0(object, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
