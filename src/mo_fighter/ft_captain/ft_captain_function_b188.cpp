#pragma force_active on
extern "C" void fn_100_B12C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_B188(void* object, short count) {
    if (object != 0) {
        fn_100_B12C(static_cast<char*>(object) + 4, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
