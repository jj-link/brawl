#pragma force_active on
extern "C" {
void fn_27_1A1E70(void*, short);
void fn_100_5708(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_5690(void* object, short value) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x190, -1);
        if (object != 0) {
            fn_100_5708(object, 0);
        }
        if (value > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
