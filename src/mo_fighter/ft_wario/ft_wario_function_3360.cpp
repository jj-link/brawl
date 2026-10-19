#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_33D0(void*, short);
extern "C" void* fn_110_4FF4(void*, short);

extern "C" void* fn_110_3360(void* object, short deleting) {
    if (object != 0) {
        fn_110_33D0(static_cast<unsigned char*>(object) + 8, -1);
        fn_110_4FF4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
