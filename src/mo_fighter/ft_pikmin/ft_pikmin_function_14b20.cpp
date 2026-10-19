#pragma force_active on
extern "C" {
void* fn_27_63EBC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_113_14B20(void* object, short deleting) {
    if (object != 0) {
        fn_27_63EBC(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
