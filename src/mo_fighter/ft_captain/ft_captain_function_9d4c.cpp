#pragma force_active on
extern "C" {
void fn_100_B780(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_9D4C(void* object, int destroy) {
    if (object != 0) {
        fn_100_B780(static_cast<char*>(object) + 4, -1);
        if (static_cast<short>(destroy) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
