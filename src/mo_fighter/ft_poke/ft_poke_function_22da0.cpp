#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_22E10(void*, short);
extern "C" void* fn_116_22F2C(void*, short);

extern "C" void* fn_116_22DA0(void* object, short deleting) {
    if (object != 0) {
        fn_116_22E10(static_cast<unsigned char*>(object) + 0x1228, -1);
        fn_116_22F2C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
