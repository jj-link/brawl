#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_100_5618(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_55A0(void* object, short deleteFlag) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<char*>(object) + 0x218, -1);

        if (object != 0) {
            fn_100_5618(object, 0);
        }

        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
