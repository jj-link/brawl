#pragma force_active on
extern "C" void* fn_27_19874C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_3140(void* object, short count) {
    if (object != 0) {
        fn_27_19874C(object, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
