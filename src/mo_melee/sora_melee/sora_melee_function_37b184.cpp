#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_37B184(void* object, short flag) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
