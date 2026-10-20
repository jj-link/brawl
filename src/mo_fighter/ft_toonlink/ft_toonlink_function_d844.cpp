#pragma force_active on
extern "C" void* fn_121_D7E4(void* object, short deleting);
extern "C" void* fn_121_D6B0(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_D844(void* object, short deleting) {
    if (object != 0) {
        fn_121_D7E4(static_cast<char*>(object) + 0x1C8, -1);
        if (object != 0) {
            fn_121_D6B0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
