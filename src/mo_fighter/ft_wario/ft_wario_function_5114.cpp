#pragma force_active on
extern "C" void* fn_110_9D30(void*, short);
extern "C" void* fn_110_3DA4(void*, short);
extern "C" void* fn_110_3E54(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_5114(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_9D30(storage + 0xE0, -1);
        fn_110_3DA4(storage + 0x30, -1);
        fn_110_3E54(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
