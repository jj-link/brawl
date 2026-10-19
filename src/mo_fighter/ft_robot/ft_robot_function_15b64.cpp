#pragma force_active on
void operator delete(void*);
extern "C" void fn_120_15AD4(void*, short);
extern "C" void fn_120_157F8(void*, short);

extern "C" void* fn_120_15B64(void* object, short deleting) {
    if (object != 0) {
        fn_120_15AD4(static_cast<unsigned char*>(object) + 0x157C, -1);
        fn_120_157F8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
