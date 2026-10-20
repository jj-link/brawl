#pragma force_active on
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_27_19EB34(void*, short);
extern "C" void* fn_27_1A4E94(void*, short);

extern "C" void* fn_116_FCB8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_93100(storage + 0x30, -1);
        fn_27_19EB34(storage + 0x10, -1);
        fn_27_1A4E94(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
