#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_133F4(void*, short);
extern "C" void* fn_120_17D44(void*, short);
extern "C" void* fn_120_17CB8(void*, short);
extern "C" void* fn_120_17C2C(void*, short);
extern "C" void* fn_120_17BA0(void*, short);

extern "C" void* fn_120_17DD0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_120_133F4(storage + 0x4B0, -1);
        fn_120_17D44(storage + 0x384, -1);
        fn_120_17CB8(storage + 0x258, -1);
        fn_120_17C2C(storage + 0x12C, -1);
        fn_120_17BA0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
