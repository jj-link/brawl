#pragma force_active on
extern "C" void* fn_93_7C54(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_93_7CD0(void* object, short deleting) {
    if (object != 0) {
        fn_93_7C54(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
