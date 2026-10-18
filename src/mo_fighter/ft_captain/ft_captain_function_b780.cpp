#pragma force_active on
extern "C" {
void fn_100_B708(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_B780(void* object, short destroy) {
    if (object != 0) {
        fn_100_B708(object, 0);
        if (destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
