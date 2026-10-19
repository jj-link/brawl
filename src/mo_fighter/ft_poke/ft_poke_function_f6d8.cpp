#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_F748(void*, short);
extern "C" void* fn_116_FB2C(void*, short);

extern "C" void* fn_116_F6D8(void* object, short deleting) {
    if (object != 0) {
        fn_116_F748(static_cast<unsigned char*>(object) + 0x1448, -1);
        fn_116_FB2C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
