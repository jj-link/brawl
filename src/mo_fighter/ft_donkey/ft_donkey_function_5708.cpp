#pragma force_active on
extern "C" void* fn_27_1A1FE4(void*, short);
extern "C" void* fn_92_5780(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_5708(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1FE4(static_cast<char*>(object) + 0x244, -1);
        if (object != 0) {
            fn_92_5780(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
