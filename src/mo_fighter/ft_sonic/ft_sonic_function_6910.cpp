#pragma force_active on
extern "C" void* fn_123_3F00(void*, short);
extern "C" void* fn_123_6988(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_6910(void* object, short deleting) {
    if (object != 0) {
        fn_123_3F00(static_cast<unsigned char*>(object) + 0xAC, -1);
        fn_123_6988(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
