#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_F7D8(void*, short);
extern "C" void* fn_116_F8A0(void*, short);
extern "C" void* fn_116_F92C(void*, short);
extern "C" void* fn_116_F9B8(void*, short);
extern "C" void* fn_116_FA44(void*, short);

extern "C" void* fn_116_F748(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_F7D8(storage + 0x2E4, -1);
        fn_116_F8A0(storage + 0x230, -1);
        fn_116_F92C(storage + 0x17C, -1);
        fn_116_F9B8(storage + 0xC8, -1);
        fn_116_FA44(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
