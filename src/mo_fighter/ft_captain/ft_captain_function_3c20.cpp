#pragma force_active on
extern "C" void fn_100_1EB8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_3C20(void* object, short flag) {
    if (object != 0) {
        fn_100_1EB8(static_cast<char*>(object) + 8, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
