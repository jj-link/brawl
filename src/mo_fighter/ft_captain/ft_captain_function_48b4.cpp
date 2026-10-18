#pragma force_active on
extern "C" void fn_100_4914(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_48B4(void* object, short flag) {
    if (object != 0) {
        fn_100_4914(static_cast<char*>(object) + 4, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
