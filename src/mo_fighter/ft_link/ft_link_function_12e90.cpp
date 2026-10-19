#pragma force_active on
extern "C" void* fn_93_12E30(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_93_12E90(void* object, short deleting) {
    if (object != 0) {
        fn_93_12E30(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
