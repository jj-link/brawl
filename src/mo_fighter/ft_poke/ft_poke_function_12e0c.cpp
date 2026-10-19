#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_12E7C(void*, short);
extern "C" void* fn_116_13130(void*, short);

extern "C" void* fn_116_12E0C(void* object, short deleting) {
    if (object != 0) {
        fn_116_12E7C(static_cast<unsigned char*>(object) + 0x1270, -1);
        fn_116_13130(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
