#pragma force_active on
extern "C" void fn_100_AB4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_AC0C(char* object, short flag) {
    if (object != 0) {
        if (object != 0) {
            fn_100_AB4C(object + 4, -1);
        }
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
