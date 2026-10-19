#pragma force_active on

extern "C" void* fn_41_53244(void*, short);
extern "C" void* fn_41_33D4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_532A8(void* object, short count) {
    if (object != 0) {
        fn_41_53244(static_cast<char*>(object) + 8, -1);
        fn_41_33D4C(object, 0);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
