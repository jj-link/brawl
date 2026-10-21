#pragma force_active on
extern "C" void* fn_120_133F4(void*, short);
extern "C" void* fn_120_15A48(void*, short);
extern "C" void* fn_120_159BC(void*, short);
extern "C" void* fn_120_15930(void*, short);
extern "C" void* fn_120_131C4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_15AD4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_133F4(storage + 0x4B0, -1);
        fn_120_15A48(storage + 0x384, -1);
        fn_120_159BC(storage + 0x258, -1);
        fn_120_15930(storage + 0x12C, -1);
        fn_120_131C4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
