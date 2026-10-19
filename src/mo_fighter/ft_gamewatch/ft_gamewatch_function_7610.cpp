#pragma force_active on
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_107_4158(void* ptr, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_7610(void* object, short flag) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_107_4158(object, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
