#pragma force_active on
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_93_1732C(void*, short);
extern "C" void* fn_27_19EB34(void*, short);
extern "C" void* fn_27_1A4E94(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_172A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_93100(storage + 0x1710, -1);
        fn_93_1732C(storage + 0x2c, -1);
        fn_27_19EB34(storage + 0x10, -1);
        fn_27_1A4E94(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
