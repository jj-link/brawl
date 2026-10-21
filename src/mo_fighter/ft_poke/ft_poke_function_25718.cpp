#pragma force_active on
extern "C" void* fn_116_257A8(void*, short);
extern "C" void* fn_116_25814(void*, short);
extern "C" void* fn_116_258A0(void*, short);
extern "C" void* fn_116_2592C(void*, short);
extern "C" void* fn_116_259B8(void*, short);
void operator delete(void*);

extern "C" void* fn_116_25718(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_257A8(storage + 0x4B0, -1);
        fn_116_25814(storage + 0x384, -1);
        fn_116_258A0(storage + 0x258, -1);
        fn_116_2592C(storage + 0x12C, -1);
        fn_116_259B8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
