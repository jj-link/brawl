#pragma force_active on
extern "C" void* fn_27_1A4980(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1F7F4(void* object, short shouldDelete) {
    if (object != 0) {
        fn_27_1A4980(object, -1);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
