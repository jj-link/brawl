#pragma force_active on
extern "C" void* fn_27_ACC5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_1ABC(void* object, short deleting) {
    if (object != 0) {
        fn_27_ACC5C(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
