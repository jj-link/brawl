#pragma force_active on
extern "C" void* fn_97_5354(void*, short);
extern "C" void* fn_97_56CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_52E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_5354(storage + 0x1DF4, -1);
        fn_97_56CC(storage + 0x4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
