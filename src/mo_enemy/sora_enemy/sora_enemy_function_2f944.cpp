#pragma force_active on
extern "C" void fn_27_B4780(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2F944(void* object, short count) {
    if (object != 0) {
        fn_27_B4780(static_cast<unsigned char*>(object) + 4, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
