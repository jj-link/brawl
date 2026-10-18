#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_4144(void* object, int flag) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0xC, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
