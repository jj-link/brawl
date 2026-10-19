#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_3588(void*, short);
extern "C" void* fn_120_35E8(void*, short);

extern "C" void* fn_120_351C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_3588(storage + 0x2030, -1);
        fn_120_35E8(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
