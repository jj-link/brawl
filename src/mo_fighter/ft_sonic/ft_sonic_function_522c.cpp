#pragma force_active on
extern "C" void* fn_123_3E1C(void*, short);
extern "C" void* fn_123_3EA0(void*, short);
extern "C" void* fn_123_52C8(void*, short);
extern "C" void* fn_123_5324(void*, short);
extern "C" void* fn_123_5D3C(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_123_522C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* base = static_cast<unsigned char*>(object);
        fn_123_3E1C(base + 0xdec, -1);
        fn_123_3EA0(base + 0xdd8, -1);
        fn_123_52C8(base + 0x930, -1);
        fn_123_5324(base + 0xbc, -1);
        fn_123_5D3C(base + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
