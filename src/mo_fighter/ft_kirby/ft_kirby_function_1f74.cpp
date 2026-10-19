#pragma force_active on
extern "C" void fn_27_1362C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_1F74(void* object, short flag) {
    if (object != 0) {
        fn_27_1362C(object, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
