#pragma force_active on
extern "C" void* fn_93_4728(void*, short);
extern "C" void* fn_93_46C8(void*, short);
extern "C" void* fn_93_17618(void*, short);
extern "C" void* fn_93_12EEC(void*, short);
extern "C" void* fn_93_17674(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_1757C(void* object, short deleting) {
    if (object != 0) {
        fn_93_4728(static_cast<char*>(object) + 0x138, -1);
        fn_93_46C8(static_cast<char*>(object) + 0x124, -1);
        fn_93_17618(static_cast<char*>(object) + 0xF4, -1);
        fn_93_12EEC(static_cast<char*>(object) + 0x50, -1);
        fn_93_17674(static_cast<char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
