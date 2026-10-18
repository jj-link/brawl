#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_3B00(void* object, short shouldDelete) {
    if (object != 0) {
        fn_27_5C674(object, -1);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
