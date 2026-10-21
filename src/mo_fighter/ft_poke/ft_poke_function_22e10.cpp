#pragma force_active on
extern "C" void* fn_116_3884(void*, short);
extern "C" void* fn_116_12F0C(void*, short);
extern "C" void* fn_116_12F98(void*, short);
extern "C" void* fn_116_13024(void*, short);
extern "C" void* fn_116_22EA0(void*, short);

extern "C" void* fn_116_22E10(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_3884(storage + 0x2bc, -1);
        fn_116_12F0C(storage + 0x208, -1);
        fn_116_12F98(storage + 0x154, -1);
        fn_116_13024(storage + 0xa0, -1);
        fn_116_22EA0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
