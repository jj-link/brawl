#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_123_6088(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_601C(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        fn_123_6088(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
