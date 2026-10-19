#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_C050(void*, short);
extern "C" void* fn_116_BF30(void*, short);

extern "C" void* fn_116_C0B0(void* object, short deleting) {
    if (object != 0) {
        fn_116_C050(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_116_BF30(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
