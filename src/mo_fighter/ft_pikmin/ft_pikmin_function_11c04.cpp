#pragma force_active on
extern "C" void* fn_113_11D54(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_113_11C04(void* object, short deleting) {
    if (object != 0) {
        fn_113_11D54(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
