#pragma force_active on

extern "C" void* fn_126_8064(void* object, short deleting);
extern "C" void fn_126_7F2C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_80C4(void* object, short deleting) {
    if (object != 0) {
        fn_126_8064(static_cast<char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_126_7F2C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
