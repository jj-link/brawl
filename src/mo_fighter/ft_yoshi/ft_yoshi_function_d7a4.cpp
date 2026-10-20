#pragma force_active on
extern "C" void fn_95_D744(void* object, short deleting);
extern "C" void fn_95_D60C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_D7A4(void* object, short deleting) {
    if (object != 0) {
        fn_95_D744(static_cast<char*>(object) + 0xec, -1);
        if (object != 0) {
            fn_95_D60C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
