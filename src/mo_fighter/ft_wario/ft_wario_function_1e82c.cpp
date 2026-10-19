#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_1E89C(void*, short);
extern "C" void* fn_110_4FF4(void*, short);

extern "C" void* fn_110_1E82C(void* object, short deleting) {
    if (object != 0) {
        fn_110_1E89C(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_110_4FF4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
