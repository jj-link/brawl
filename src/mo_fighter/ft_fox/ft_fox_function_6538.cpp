#pragma force_active on
extern "C" void* fn_97_B7E0(void*, short);
extern "C" void* fn_97_62C8(void*, short);
extern "C" void* fn_97_6338(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_6538(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_B7E0(storage + 0xE0, -1);
        fn_97_62C8(storage + 0x30, -1);
        fn_97_6338(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
