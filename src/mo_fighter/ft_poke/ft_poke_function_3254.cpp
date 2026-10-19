#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_32C4(void*, short);
extern "C" void* fn_116_53D8(void*, short);

extern "C" void* fn_116_3254(void* object, short deleting) {
    if (object != 0) {
        fn_116_32C4(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_116_53D8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
