#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_136A0(void*, short);
extern "C" void* fn_121_13614(void*, short);
extern "C" void* fn_121_13588(void*, short);
extern "C" void* fn_121_134FC(void*, short);
extern "C" void* fn_121_13470(void*, short);

extern "C" void* fn_121_1370C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_136A0(storage + 0x4B0, -1);
        fn_121_13614(storage + 0x384, -1);
        fn_121_13588(storage + 0x258, -1);
        fn_121_134FC(storage + 0x12C, -1);
        fn_121_13470(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
