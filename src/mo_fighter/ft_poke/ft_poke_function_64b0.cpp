#pragma force_active on
void operator delete(void* p);
extern "C" void* fn_27_565F0(void* p, short n);
extern "C" void* fn_116_651C(void* p, short n);

extern "C" void* fn_116_64B0(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        fn_116_651C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
