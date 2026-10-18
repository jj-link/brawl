#pragma force_active on
extern "C" void* fn_121_4728(void*, short);
extern "C" void* fn_121_46C8(void*, short);
extern "C" void* fn_121_53F0(void*, short);
extern "C" void* fn_121_5378(void*, short);
extern "C" void* fn_121_4978(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_544C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_4728(storage + 0xdc0, -1);
        fn_121_46C8(storage + 0xdac, -1);
        fn_121_53F0(storage + 0x930, -1);
        fn_121_5378(storage + 0xbc, -1);
        fn_121_4978(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
