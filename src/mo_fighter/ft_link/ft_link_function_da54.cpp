#pragma force_active on
extern "C" void* fn_93_D9DC(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_93_DA54(void* object, short deleting) {
    if (object != 0) {
        fn_93_D9DC(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
