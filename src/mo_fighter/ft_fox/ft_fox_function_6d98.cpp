#pragma force_active on
extern "C" void fn_27_1A15B8(void*, short);
extern "C" void fn_97_6E10(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_97_6D98(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x138, -1);
        if (object != 0) {
            fn_97_6E10(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
