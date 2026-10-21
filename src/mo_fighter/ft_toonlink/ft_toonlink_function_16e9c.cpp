#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_136A0(void*, short);
extern "C" void* fn_121_16F2C(void*, short);
extern "C" void* fn_121_16FB8(void*, short);
extern "C" void* fn_121_17044(void*, short);
extern "C" void* fn_121_170D0(void*, short);

extern "C" void* fn_121_16E9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_136A0(storage + 0x4B0, -1);
        fn_121_16F2C(storage + 0x384, -1);
        fn_121_16FB8(storage + 0x258, -1);
        fn_121_17044(storage + 0x12C, -1);
        fn_121_170D0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
