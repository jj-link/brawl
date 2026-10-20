#pragma force_active on
extern "C" void* fn_97_CE64(void* object, short deleting);
extern "C" void* fn_97_CD34(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_97_CEC4(void* object, short deleting) {
    if (object != 0) {
        fn_97_CE64(static_cast<char*>(object) + 0x94, -1);
        if (object != 0) {
            fn_97_CD34(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
