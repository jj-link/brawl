#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_108_6CE0(void*, short);

extern "C" void* fn_108_6C68(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x138, -1);
        if (object != 0) {
            fn_108_6CE0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
