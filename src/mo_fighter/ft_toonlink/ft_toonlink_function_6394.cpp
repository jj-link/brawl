#pragma force_active on
extern "C" void* fn_27_A0C74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_6394(void* object, int flag) {
    if (object != 0) {
        fn_27_A0C74(object, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
