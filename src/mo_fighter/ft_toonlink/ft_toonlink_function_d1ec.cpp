#pragma force_active on
extern "C" void fn_121_D18C(void* object, short deleting);
extern "C" void fn_121_D05C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_D1EC(void* object, short deleting) {
    if (object != 0) {
        fn_121_D18C(static_cast<unsigned char*>(object) + 0x94, -1);
        if (object != 0) {
            fn_121_D05C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
