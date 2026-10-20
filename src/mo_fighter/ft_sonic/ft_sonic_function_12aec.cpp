#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_12B64(void*, short);
extern "C" void* fn_123_12BA4(void*, short);
extern "C" void* fn_123_12C04(void*, short);

extern "C" void* fn_123_12AEC(void* object, short deleting) {
    if (object != 0) {
        fn_123_12B64(static_cast<unsigned char*>(object) + 0xB0, -1);
        fn_123_12BA4(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_123_12C04(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
