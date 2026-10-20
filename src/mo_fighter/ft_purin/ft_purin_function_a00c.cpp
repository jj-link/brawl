#pragma force_active on
extern "C" {
void* fn_124_9FAC(void*, short);
void* fn_124_9E78(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_124_A00C(void* object, int destroyFlag) {
    if (object != 0) {
        fn_124_9FAC((char*)object + 0x1c8, -1);
        if (object != 0) {
            fn_124_9E78(object, 0);
        }
        if ((short)destroyFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
