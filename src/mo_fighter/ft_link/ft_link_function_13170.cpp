#pragma force_active on
extern "C" void* fn_93_130D0(void*, short);
extern "C" void* fn_93_13110(void*, short);
extern "C" void* fn_93_1305C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_13170(void* object, short deleting) {
    if (object != 0) {
        fn_93_130D0(static_cast<unsigned char*>(object) + 0xB0, -1);
        fn_93_13110(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_93_1305C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
