#pragma force_active on
extern "C" void* fn_27_6880C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_41A4(void* object, int flag) {
    if (object != 0) {
        fn_27_6880C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
