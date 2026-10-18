#pragma force_active on
extern "C" void* fn_27_A0C34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_30AC(void* object, int shouldDelete) {
    if (object != 0) {
        fn_27_A0C34(object, -1);
        if ((short)shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
