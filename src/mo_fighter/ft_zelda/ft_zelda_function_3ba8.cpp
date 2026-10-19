#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_3BA8(void* object, short flag) {
    if (object != 0) {
        fn_27_5C674(object, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
